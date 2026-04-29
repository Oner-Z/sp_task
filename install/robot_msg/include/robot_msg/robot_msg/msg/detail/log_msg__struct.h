// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msg:msg/LogMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSG__MSG__DETAIL__LOG_MSG__STRUCT_H_
#define ROBOT_MSG__MSG__DETAIL__LOG_MSG__STRUCT_H_

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
// Member 'node_name'
// Member 'diagnostic_info'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LogMsg in the package robot_msg.
typedef struct robot_msg__msg__LogMsg
{
  std_msgs__msg__Header header;
  double fps;
  rosidl_runtime_c__String node_name;
  rosidl_runtime_c__String diagnostic_info;
} robot_msg__msg__LogMsg;

// Struct for a sequence of robot_msg__msg__LogMsg.
typedef struct robot_msg__msg__LogMsg__Sequence
{
  robot_msg__msg__LogMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msg__msg__LogMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSG__MSG__DETAIL__LOG_MSG__STRUCT_H_
