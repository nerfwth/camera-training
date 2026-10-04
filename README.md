# Industrial Camera Training

大恒工业相机与 spdlog 日志培训任务。

## 完成功能

- Galaxy SDK 枚举并打开大恒工业相机
- 根据序列号选择设备
- 曝光、增益、伽马参数调节
- Bayer 图像转换为 BGR
- OpenCV 实时显示图像
- 实时 FPS 显示
- 使用 rm_log（基于 spdlog）统一输出调试日志
- 日志同时输出到终端和日志文件

## 测试设备

Daheng Imaging MER2-230-168U3C-L

实机测试帧率约 99 FPS。

## 编译运行

```bash
mkdir build
cd build
cmake ..
make -j8

./daheng_demo <相机序列号>
