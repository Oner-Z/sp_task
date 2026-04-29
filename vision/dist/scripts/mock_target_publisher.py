#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped

class MockTargetPublisher(Node):
    def __init__(self):
        super().__init__('mock_target_publisher')

        # Publisher
        self.publisher = self.create_publisher(PointStamped, '/target_position', 10)

        # Timer (10 Hz)
        self.timer = self.create_timer(0.1, self.publish_target)

        # Static target position (in map frame)
        self.target_x = 15.148932
        self.target_y = 15.831843
        self.target_z = 2.0

        self.get_logger().info(f'Publishing target at ({self.target_x}, {self.target_y}, {self.target_z})')

    def publish_target(self):
        msg = PointStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'
        msg.point.x = self.target_x
        msg.point.y = self.target_y
        msg.point.z = self.target_z

        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = MockTargetPublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
