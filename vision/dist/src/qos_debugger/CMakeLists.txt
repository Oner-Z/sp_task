cmake_minimum_required(VERSION 3.8)
project(qos_debugger)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(robot_msg REQUIRED)

add_executable(qos_debugger_node src/qos_debugger_node.cpp)
ament_target_dependencies(qos_debugger_node
  rclcpp
  sensor_msgs
  robot_msg
)

install(TARGETS
  qos_debugger_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
