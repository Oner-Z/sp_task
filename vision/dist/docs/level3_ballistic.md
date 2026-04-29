# Level 3: 吊射弹道解算

## 背景知识

### 抛物线运动
在重力作用下，弹丸的运动轨迹是抛物线。给定初速度 v₀ 和发射角度 θ：

**水平方向**（无加速度）：
```
x(t) = v₀ · cos(θ) · t
```

**垂直方向**（重力加速度 g）：
```
z(t) = v₀ · sin(θ) · t - ½ · g · t²
```

### 云台控制
云台有两个自由度：
- **Yaw（偏航角）**：水平旋转，控制左右方向
- **Pitch（俯仰角）**：垂直旋转，控制上下方向

## 任务目标

实现一个弹道解算节点，计算云台需要的 Pitch 和 Yaw 角度来击中目标。

## 物理常量

```cpp
constexpr double GRAVITY = 9.8;          // m/s²
constexpr double BULLET_VELOCITY = 20.0; // m/s
```

假设：
- 真空环境（无空气阻力）
- 子弹初速恒定
- 忽略科氏力

## 输入接口

### 1. 目标位置
- **话题**：`/target_position`
- **消息类型**：`geometry_msgs/PointStamped`
- **坐标系**：`map`
- **频率**：10 Hz

### 2. 云台位置
通过 TF 树获取：
- **Frame ID**: `gimbal_link`
- **Parent Frame**: `map`

使用 `tf2_ros::Buffer` 和 `tf2_ros::TransformListener` 查询变换。

## 输出接口

- **话题**：`/gimbal_control`
- **消息类型**：`robot_msg/GimbalControlMsg`
- **字段**：
  - `header`: 标准 ROS header
  - `pitch`: 俯仰角（弧度，向上为正）
  - `yaw`: 偏航角（弧度，逆时针为正）

## 实现步骤
**在这里介绍你的实现思路**

## 验证方法
**在这里使用图片，代码，描述等方式补全你的操作流程和结果**
