# Level 2: 基于先验地图的全局重定位

## 背景知识

### 全局重定位
在已知地图的环境中，机器人可以通过雷达获得周围环境的信息，然后将这些信息与地图进行匹配，就可以知道自己在地图的什么位置。

### GICP 算法
Generalized Iterative Closest Point (GICP) 是一种点云配准算法，通过迭代优化找到两个点云之间的最佳变换关系。

### 坐标系关系
- `map`: 全局地图坐标系（固定）
- `odom`: 里程计坐标系（随机器人移动）
- `base_link`: 机器人本体坐标系

重定位的目标是计算 `map -> odom` 的变换。

## 任务目标

补全 `small_gicp_relocalization` 包中的 GICP 配准代码，实现全局重定位功能。可以参考开源代码

## 问题描述

`src/relocalization_node.cpp` 中的核心配准代码已被删除。当前代码：
- ✅ 加载先验地图
- ✅ 订阅当前点云扫描
- ✅ TF 发布框架
- ❌ **缺少 GICP 配准循环**

## 输入接口

1. **先验地图**：通过参数指定 PCD 文件路径
   ```bash
   ros2 run small_gicp_relocalization relocalization_node \
     --ros-args -p map_path:=/path/to/map.pcd
   ```

2. **当前扫描**：订阅 `/livox/lidar` 话题

## 实现步骤

**在这里介绍你的实现思路**

## 输出接口

发布 TF 变换：`map -> odom`

## 验证方法

**在这里使用图片，代码，描述等方式补全你的操作流程和结果**

### 步骤 1: 准备先验地图
使用 Level 1 生成的 PCD 文件作为先验地图。

### 步骤 2: 启动重定位节点
```bash
ros2 run small_gicp_relocalization relocalization_node \
  --ros-args -p map_path:=<path to the map file>
```

### 步骤 3: 播放动态 bag
```bash
ros2 bag play assets/rosbag_trimmed
```

### 步骤 4: 检查结果
```bash

```

## 提示

- 首要的目标是理解并跑通流程，暂时不需要追求定位的精度