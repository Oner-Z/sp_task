#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/registration/gicp.h>

class RelocalizationNode : public rclcpp::Node {
public:
    RelocalizationNode() : Node("relocalization_node") {
        // Declare parameters
        this->declare_parameter("map_path", "");
        this->get_parameter("map_path", map_path_);

        // Load prior map
        map_cloud_.reset(new pcl::PointCloud<pcl::PointXYZ>);
        if (pcl::io::loadPCDFile(map_path_, *map_cloud_) == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to load map from: %s", map_path_.c_str());
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Loaded map with %zu points", map_cloud_->size());

        // Subscribe to current scan
        cloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "/livox/lidar/pointcloud",
            rclcpp::SensorDataQoS(),
            std::bind(&RelocalizationNode::cloud_callback, this, std::placeholders::_1)
        );

        // TF broadcaster
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        RCLCPP_INFO(this->get_logger(), "Relocalization node initialized");
    }

private:
    void cloud_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
        // Convert ROS message to PCL
        RCLCPP_INFO(this->get_logger(), "Received point cloud with %u points", msg->width * msg->height);
        pcl::PointCloud<pcl::PointXYZ>::Ptr current_scan(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::fromROSMsg(*msg, *current_scan);
        
        // TODO: Perform GICP registration here
        // The core registration loop has been removed for the exam
        // Candidates need to implement:
        // 1. Initialize transformation matrix
        // 2. Run GICP alignment between current_scan and map_cloud_
        // 3. Extract the transformation result
        //TODO: 在此处完成 GICP 配准
        // 核心配准循环已移除以供考试使用
        // 考生需要实现：
        // 1. 初始化变换矩阵
        // 2. 对 current_scan 和 map_cloud_ 执行 GICP 对齐
        // 3. 提取变换结果
        pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> gicp;

        gicp.setInputSource(current_scan);
        gicp.setInputTarget(map_cloud_);

        gicp.setMaximumIterations(50);
        gicp.setTransformationEpsilon(1e-6);
        gicp.setEuclideanFitnessEpsilon(1e-2);
        gicp.setMaxCorrespondenceDistance(2.0);

        pcl::PointCloud<pcl::PointXYZ> aligned_scan;
        gicp.align(aligned_scan);

        // Placeholder transformation (identity)
        Eigen::Matrix4f transformation;
        if (gicp.hasConverged()) {
            transformation = gicp.getFinalTransformation();
            RCLCPP_INFO(this->get_logger(), "GICP converged with score: %f", gicp.getFitnessScore());
        } else {
            RCLCPP_WARN(this->get_logger(), "GICP did not converge");
            transformation = Eigen::Matrix4f::Identity();
        }


        // Publish TF: map -> odom
        publish_transform(transformation, msg->header.stamp);
    }

    void publish_transform(const Eigen::Matrix4f& transform, const rclcpp::Time& stamp) {
        geometry_msgs::msg::TransformStamped t;
        t.header.stamp = stamp;
        t.header.frame_id = "map";
        t.child_frame_id = "odom";

        // Extract translation
        t.transform.translation.x = transform(0, 3);
        t.transform.translation.y = transform(1, 3);
        t.transform.translation.z = transform(2, 3);

        // Extract rotation (convert to quaternion)
        Eigen::Matrix3f rotation = transform.block<3, 3>(0, 0);
        Eigen::Quaternionf q(rotation);
        t.transform.rotation.x = q.x();
        t.transform.rotation.y = q.y();
        t.transform.rotation.z = q.z();
        t.transform.rotation.w = q.w();

        tf_broadcaster_->sendTransform(t);
    }

    std::string map_path_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr map_cloud_;
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_sub_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr total_scan{new pcl::PointCloud<pcl::PointXYZ>};
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RelocalizationNode>());
    rclcpp::shutdown();
    return 0;
}
