cmake_minimum_required(VERSION 3.8)
project(ballistic_solver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(robot_msg REQUIRED)

include_directories(include)

add_executable(solver_node src/ballistic_solver_node.cpp)
ament_target_dependencies(solver_node
  rclcpp
  geometry_msgs
  tf2_ros
  robot_msg
)

install(TARGETS
  solver_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include
)

ament_package()
