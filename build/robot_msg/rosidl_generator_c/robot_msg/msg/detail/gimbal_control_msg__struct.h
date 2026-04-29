// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msg:msg/GimbalControlMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSG__MSG__DETAIL__GIMBAL_CONTROL_MSG__STRUCT_H_
#define ROBOT_MSG__MSG__DETAIL__GIMBAL_CONTROL_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/GimbalControlMsg in the package robot_msg.
typedef struct robot_msg__msg__GimbalControlMsg
{
  std_msgs__msg__Header header;
  double pitch;
  double yaw;
} robot_msg__msg__GimbalControlMsg;

// Struct for a sequence of robot_msg__msg__GimbalControlMsg.
typedef struct robot_msg__msg__GimbalControlMsg__Sequence
{
  robot_msg__msg__GimbalControlMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msg__msg__GimbalControlMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSG__MSG__DETAIL__GIMBAL_CONTROL_MSG__STRUCT_H_
