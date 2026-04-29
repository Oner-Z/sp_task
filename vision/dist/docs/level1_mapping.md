# Level 1: 基础建图与 2D 栅格化

## 背景知识
任务首先需要定位。比如怎么知道自己在学校的什么位置？那首先你需要知道整个学校长什么样子，你才能通过周围的环境知道自己在哪里。使用激光雷达定位也是如此。首先，我们需要使用激光雷达扫描的点云数据对整个环境进行建立地图

### SLAM 建图
SLAM (Simultaneous Localization and Mapping) 是机器人同时进行定位和地图构建的技术。FAST-LIO 是一种基于激光雷达和 IMU 的高效 SLAM 算法。

## 任务目标
本关卡你使用 FAST-LIO 建立地图

## 完整流程

**在这里使用图片，代码，描述等方式补全你的操作流程和结果**

### 0. 前置准备
```bash
ros2 run tf2_ros static_transform_publisher 0.18 0.05 0.16 0.0 0 0 base_link livox_frame
```

**思考题：上面这句命令是什么含义**

### 1. 运行 FAST-LIO
```bash

```

### 2. 播放 bag：
```bash
ros2 bag play assets/rosbag_mapping
```

### 3. 存图
```bash
ros2 service call /map_save std_srvs/srv/Trigger "{}"
```

**怎么知道建的图怎么样？建立的图在哪里呢？**

## 提示

- 使用 `pcl_viewer` 或 CloudCompare 查看 PCD 文件