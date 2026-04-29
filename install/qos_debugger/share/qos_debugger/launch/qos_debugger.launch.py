from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='qos_debugger',
            executable='qos_debugger_node',
            name='qos_debugger_node',
            output='screen'
        )
    ])
