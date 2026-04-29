// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_msg:msg/LogMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSG__MSG__DETAIL__LOG_MSG__STRUCT_HPP_
#define ROBOT_MSG__MSG__DETAIL__LOG_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_msg__msg__LogMsg __attribute__((deprecated))
#else
# define DEPRECATED__robot_msg__msg__LogMsg __declspec(deprecated)
#endif

namespace robot_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LogMsg_
{
  using Type = LogMsg_<ContainerAllocator>;

  explicit LogMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fps = 0.0;
      this->node_name = "";
      this->diagnostic_info = "";
    }
  }

  explicit LogMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    node_name(_alloc),
    diagnostic_info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fps = 0.0;
      this->node_name = "";
      this->diagnostic_info = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _fps_type =
    double;
  _fps_type fps;
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_name_type node_name;
  using _diagnostic_info_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _diagnostic_info_type diagnostic_info;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__fps(
    const double & _arg)
  {
    this->fps = _arg;
    return *this;
  }
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }
  Type & set__diagnostic_info(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->diagnostic_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_msg::msg::LogMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_msg::msg::LogMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_msg::msg::LogMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_msg::msg::LogMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_msg::msg::LogMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_msg::msg::LogMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_msg::msg::LogMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_msg::msg::LogMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_msg::msg::LogMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_msg::msg::LogMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_msg__msg__LogMsg
    std::shared_ptr<robot_msg::msg::LogMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_msg__msg__LogMsg
    std::shared_ptr<robot_msg::msg::LogMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LogMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->fps != other.fps) {
      return false;
    }
    if (this->node_name != other.node_name) {
      return false;
    }
    if (this->diagnostic_info != other.diagnostic_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const LogMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LogMsg_

// alias to use template instance with default allocator
using LogMsg =
  robot_msg::msg::LogMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_msg

#endif  // ROBOT_MSG__MSG__DETAIL__LOG_MSG__STRUCT_HPP_
