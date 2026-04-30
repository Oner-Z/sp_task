#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "robot_msg/msg/log_msg.hpp"

class QosDebuggerNode : public rclcpp::Node {
public:
    QosDebuggerNode() : Node("qos_debugger_node") {
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
        // qos.reliable();
        qos.best_effort();
        cloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "/livox/lidar/pointcloud",
            qos,
            std::bind(&QosDebuggerNode::cloud_callback, this, std::placeholders::_1)
        );
        sensor_pub_ = this->create_publisher<robot_msg::msg::LogMsg>(
            "sensor_monitor",
            qos
        );
    }
private:
    void cloud_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "PointCloud received. Timestamp: %d", msg->header.stamp.sec);
        now_time_stamp = msg->header.stamp.sec + msg->header.stamp.nanosec * 1e-9;
        if (last_time_stamp > 0.0) {
            fps = 1.0 / (now_time_stamp - last_time_stamp);
            RCLCPP_INFO(this->get_logger(), "FPS: %f", fps);
        }

        log_msg.header.stamp = this->now();
        log_msg.fps = fps;
        log_msg.node_name = "qos_debugger_node";
        log_msg.diagnostic_info = "this is a fps monitor";
        sensor_pub_->publish(log_msg);

        last_time_stamp = now_time_stamp;
    }

    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_sub_;
    rclcpp::Publisher<robot_msg::msg::LogMsg>::SharedPtr sensor_pub_;
    double last_time_stamp = 0.0;
    double now_time_stamp;
    double fps;
    robot_msg::msg::LogMsg log_msg;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<QosDebuggerNode>());
    rclcpp::shutdown();
    return 0;
}
