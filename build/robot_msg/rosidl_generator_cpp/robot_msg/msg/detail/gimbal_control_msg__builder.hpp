// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msg:msg/GimbalControlMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSG__MSG__DETAIL__GIMBAL_CONTROL_MSG__BUILDER_HPP_
#define ROBOT_MSG__MSG__DETAIL__GIMBAL_CONTROL_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msg/msg/detail/gimbal_control_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msg
{

namespace msg
{

namespace builder
{

class Init_GimbalControlMsg_yaw
{
public:
  explicit Init_GimbalControlMsg_yaw(::robot_msg::msg::GimbalControlMsg & msg)
  : msg_(msg)
  {}
  ::robot_msg::msg::GimbalControlMsg yaw(::robot_msg::msg::GimbalControlMsg::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msg::msg::GimbalControlMsg msg_;
};

class Init_GimbalControlMsg_pitch
{
public:
  explicit Init_GimbalControlMsg_pitch(::robot_msg::msg::GimbalControlMsg & msg)
  : msg_(msg)
  {}
  Init_GimbalControlMsg_yaw pitch(::robot_msg::msg::GimbalControlMsg::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_GimbalControlMsg_yaw(msg_);
  }

private:
  ::robot_msg::msg::GimbalControlMsg msg_;
};

class Init_GimbalControlMsg_header
{
public:
  Init_GimbalControlMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalControlMsg_pitch header(::robot_msg::msg::GimbalControlMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GimbalControlMsg_pitch(msg_);
  }

private:
  ::robot_msg::msg::GimbalControlMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msg::msg::GimbalControlMsg>()
{
  return robot_msg::msg::builder::Init_GimbalControlMsg_header();
}

}  // namespace robot_msg

#endif  // ROBOT_MSG__MSG__DETAIL__GIMBAL_CONTROL_MSG__BUILDER_HPP_
