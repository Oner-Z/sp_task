from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'map_path',
            default_value='',
            description='Path to the prior map PCD file'
        ),
        Node(
            package='small_gicp_relocalization',
            executable='relocalization_node',
            name='relocalization_node',
            output='screen',
            parameters=[{
                'map_path': LaunchConfiguration('map_path')
            }]
        )
    ])
