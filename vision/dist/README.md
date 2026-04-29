# 视觉组考核试题

同学你好，欢迎打开这份SuperPower战队视觉组春季招新考核试题。这道试题取材于一个使用激光雷达定位+弹道解算的赛场实际应用场景。我们希望你在完成的过程中就能够掌握这个任务的基本流程，也希望你能有所收获。以下是题目的要求。

## 环境要求

- **操作系统**: Ubuntu 22.04 LTS，建议在WSL2中运行
- **ROS 2 版本**: Humble
- **编译工具**: colcon
- **依赖库**: PCL, OpenCV, Eigen3, Boost


## 评价标准，提交方法与答题说明
题目不设置机械的评分标准。我们会综合查看你的debug思路，代码质量，版本管理能力等方面进行考量。即使没有做完所有题目，也可以提交。

提交时，删除build, intsll, assets log四个文件夹之后，将剩余文件打包成.zip格式的压缩包发送给QQ群的 @奚睿豪

答题时，允许使用AI辅助。**但是必须在每一问的md文件中通过截图等手段说明解决问题的思路和过程。**

## 快速开始

### 0. 安装WSL2
请自行搜索官方指南，微软已经给出了比较好的指导。注意，安装的ubuntu版本需要是22.04，不保证其他版本的系统也能够运行。

### 1. 安装依赖
在wsl2的ubuntu系统中进行如下操作。后续若无特殊说明，则项目所有代码运行都是在ubuntu系统中。
```bash
参考该链接安装ros2 humble：https://blog.csdn.net/weixin_55944949/article/details/140373710

# 安装依赖库
sudo apt update

sudo apt install libopencv-dev \
  libpcl-dev ros-humble-rclpy \
  ros-humble-rclcpp-components \
  ros-humble-pcl-ros

如有其他依赖可使用类似方式安装或自行搜索解决
```

### 3. 编译工作空间

```bash
cd <path to your project>/test

# 一次性编译所有包
colcon build

# 加载环境
source install/setup.bash
```

## 考核关卡

整道题目分为四个等级。除了level 0以外，之后的level依次依赖于前一级的实现。以下是每道题目的简单叙述，详细说明位于docs文件夹内

### Level 0: ROS 2 通信机制与 QoS 调试

**任务说明**: 修复配置错误，添加 FPS 计算和消息发布功能。

**位置**: `src/qos_debugger/src/qos_debugger_node.cpp`

**文档**: [docs/level0_qos_debug.md](docs/level0_qos_debug.md)

**运行**:
```bash
ros2 run qos_debugger qos_debugger_node
ros2 topic echo /sensor_monitor
```

**考核点**:
- 解决信息接收失败问题
- 时间差分计算 FPS
- 发布诊断消息到 `/sensor_monitor`

---

### Level 1: 基础建图

**任务**: 使用提供的rosbag，运行fastlio代码完成建图

**位置**:
- `src/FAST_LIO/config/mid360.yaml`（fastlio代码）

**文档**: [docs/level1_mapping.md](docs/level1_mapping.md)

**运行简述**:
```bash
# 建图
ros2 launch fast_lio mapping.launch.py

ros2 run tf2_ros static_transform_publisher 0.18 0.05 0.16 0.0 0 0 base_link livox_frame

ros2 bag play assets/rosbag_mapping/

#完成之后保存地图
ros2 service call /map_save std_srvs/srv/Trigger "{}"
```

**考核点**:
- 运行fastlio和建图过程的理解
- rviz界面的基本使用
---

### Level 2: 基于先验地图的重定位

**任务**: 在使用Level1中建立的地图的情况下，播放另一个rosbag模拟赛场情况，使用补全的 GICP 配准算法，实现重定位。

**位置**: `src/small_gicp_relocalization/src/relocalization_node.cpp`

**文档**: [docs/level2_relocalization.md](docs/level2_relocalization.md)

**运行**:
```bash
ros2 run small_gicp_relocalization relocalization_node --ros-args -p map_path:=./src/FAST_LIO/PCD/map_combine.pcd

ros2 bag play assets/rosbag_trimmed

# 检查结果
```

**考核点**:
- 理解重定位过程与算法
- 理解坐标变换

---

### Level 3: 弹道解算

**任务**: 对于level2获得的结果，实现弹道解算节点，计算云台 Pitch 和 Yaw 角度。

**位置**: `src/ballistic_solver/src/ballistic_solver_node.cpp`

**文档**: [docs/level3_ballistic.md](docs/level3_ballistic.md)

**运行**:
```bash
# 模拟发送目标位置
python3 mock_target_publisher.py

# 从 level 2 中获得自身坐标

# 运行弹道解算
ros2 run ballistic_solver solver_node

# 查看输出
```

**考核点**:
- TF 监听和坐标转换
- 弹道方程求解（Yaw + Pitch）
- 消息发布和接口

## 工作空间结构

```
test/
├── src/                        # ROS 2 源码目录
│   ├── robot_msg/              # 自定义消息包，原则上不需要修改
│   ├── qos_debugger/           # Level 0: 入门调试
│   ├── FAST-LIO/               # Level 1: SLAM 建图，原则上不需要修改
│   ├── small_gicp_relocalization/  # Level 2: 重定位
│   └── ballistic_solver/       # Level 3: 弹道解算
├── docs/                       # 考题文档
│   ├── level0_debug.md
│   ├── level1_mapping.md
│   ├── level2_relocalization.md
│   └── level3_ballistic.md
├── scripts/                    # 辅助脚本，原则上不需要修改
│   └── mock_target_publisher.py
└── README.md                   # 本文件
```

## 数据准备
本考核环境需要两个 ROS 2 Bag 文件：

1. **assets/rosbag_mapping**: 用于 Level 1 建图
   - 包含话题: `/livox/lidar`, `/livox/imu`等
   - 场景: 静态环境完整扫描

2. **assets/rosbag_trimmed**: 用于 Level 2，3的重定位过程
   - 包含话题: `/livox/lidar`, `/livox/imu`等
   - 场景: 局部区域移动的数据

**祝顺利！**
