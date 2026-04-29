#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

class QosDebuggerNode : public rclcpp::Node {
public:
    QosDebuggerNode() : Node("qos_debugger_node") {
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
        qos.reliable();

        cloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "/livox/lidar/pointcloud",
            qos,
            std::bind(&QosDebuggerNode::cloud_callback, this, std::placeholders::_1)
        );
    }
private:
    void cloud_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "PointCloud received. Timestamp: %d", msg->header.stamp.sec);
    }
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_sub_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<QosDebuggerNode>());
    rclcpp::shutdown();
    return 0;
}
