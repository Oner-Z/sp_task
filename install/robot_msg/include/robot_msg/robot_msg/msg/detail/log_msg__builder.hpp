// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msg:msg/LogMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSG__MSG__DETAIL__LOG_MSG__BUILDER_HPP_
#define ROBOT_MSG__MSG__DETAIL__LOG_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msg/msg/detail/log_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msg
{

namespace msg
{

namespace builder
{

class Init_LogMsg_diagnostic_info
{
public:
  explicit Init_LogMsg_diagnostic_info(::robot_msg::msg::LogMsg & msg)
  : msg_(msg)
  {}
  ::robot_msg::msg::LogMsg diagnostic_info(::robot_msg::msg::LogMsg::_diagnostic_info_type arg)
  {
    msg_.diagnostic_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msg::msg::LogMsg msg_;
};

class Init_LogMsg_node_name
{
public:
  explicit Init_LogMsg_node_name(::robot_msg::msg::LogMsg & msg)
  : msg_(msg)
  {}
  Init_LogMsg_diagnostic_info node_name(::robot_msg::msg::LogMsg::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_LogMsg_diagnostic_info(msg_);
  }

private:
  ::robot_msg::msg::LogMsg msg_;
};

class Init_LogMsg_fps
{
public:
  explicit Init_LogMsg_fps(::robot_msg::msg::LogMsg & msg)
  : msg_(msg)
  {}
  Init_LogMsg_node_name fps(::robot_msg::msg::LogMsg::_fps_type arg)
  {
    msg_.fps = std::move(arg);
    return Init_LogMsg_node_name(msg_);
  }

private:
  ::robot_msg::msg::LogMsg msg_;
};

class Init_LogMsg_header
{
public:
  Init_LogMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LogMsg_fps header(::robot_msg::msg::LogMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LogMsg_fps(msg_);
  }

private:
  ::robot_msg::msg::LogMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msg::msg::LogMsg>()
{
  return robot_msg::msg::builder::Init_LogMsg_header();
}

}  // namespace robot_msg

#endif  // ROBOT_MSG__MSG__DETAIL__LOG_MSG__BUILDER_HPP_
