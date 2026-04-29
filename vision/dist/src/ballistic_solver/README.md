# Ballistic Solver - Level 3 考题

## 任务目标

实现一个弹道解算节点，计算云台需要的 Pitch 和 Yaw 角度来击中目标。

## 物理常量

- 重力加速度：g = 9.8 m/s²
- 子弹初速：v₀ = 20 m/s
- 假设：真空环境（无空气阻力）

## 输入接口

1. **目标位置**：订阅 `/target_position` 话题
   - 消息类型：`geometry_msgs/PointStamped`
   - 坐标系：`map`
   - 频率：10 Hz

2. **云台位置**：通过 TF 树获取
   - Frame ID: `gimbal_link`
   - Parent Frame: `map`

## 输出接口

发布云台控制消息到 `/gimbal_control` 话题：
- 消息类型：`robot_msg/GimbalControlMsg`
- 字段：
  - `header`: 标准 ROS header
  - `pitch`: 俯仰角（弧度）
  - `yaw`: 偏航角（弧度）

## 实现提示

### 1. 坐标转换
使用 TF2 获取云台在 map 坐标系下的位置。

### 2. 弹道方程
对于抛物线运动：
- 水平方向：x = v₀ · cos(θ) · t
- 垂直方向：z = v₀ · sin(θ) · t - 0.5 · g · t²

其中 θ 是发射角度（pitch）。

### 3. 求解步骤
1. 计算目标相对于云台的位置向量
2. 计算水平距离和高度差
3. 求解 Yaw 角度（水平方向）
4. 求解 Pitch 角度（考虑重力影响）

### 4. Pitch 角度求解
这是一个二次方程问题。给定水平距离 d 和高度差 h：

可以推导出：
```
tan(θ) = (v₀² ± sqrt(v₀⁴ - g(gd² + 2hv₀²))) / (gd)
```

选择较小的角度（低弹道）或较大的角度（高弹道）。

## 验证方法

```bash
# 终端 1: 启动 mock 靶点发布器
ros2 run scripts mock_target_publisher.py

# 终端 2: 发布静态 TF（模拟云台位置）
ros2 run tf2_ros static_transform_publisher 0 0 0.5 0 0 0 map gimbal_link

# 终端 3: 运行弹道解算节点
ros2 run ballistic_solver solver_node

# 终端 4: 查看输出
ros2 topic echo /gimbal_control
```

## 评分标准

- TF 监听和坐标转换 (8分)
- 弹道方程求解正确性 (15分)
- 消息发布和接口 (7分)
