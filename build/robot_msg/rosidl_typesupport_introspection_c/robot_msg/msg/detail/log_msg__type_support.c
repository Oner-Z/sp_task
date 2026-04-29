// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_msg:msg/LogMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_msg/msg/detail/log_msg__rosidl_typesupport_introspection_c.h"
#include "robot_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_msg/msg/detail/log_msg__functions.h"
#include "robot_msg/msg/detail/log_msg__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `node_name`
// Member `diagnostic_info`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_msg__msg__LogMsg__init(message_memory);
}

void robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_fini_function(void * message_memory)
{
  robot_msg__msg__LogMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msg__msg__LogMsg, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msg__msg__LogMsg, fps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msg__msg__LogMsg, node_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "diagnostic_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msg__msg__LogMsg, diagnostic_info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_members = {
  "robot_msg__msg",  // message namespace
  "LogMsg",  // message name
  4,  // number of fields
  sizeof(robot_msg__msg__LogMsg),
  robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_member_array,  // message members
  robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_type_support_handle = {
  0,
  &robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msg, msg, LogMsg)() {
  robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_type_support_handle.typesupport_identifier) {
    robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_msg__msg__LogMsg__rosidl_typesupport_introspection_c__LogMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
