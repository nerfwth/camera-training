#ifndef CAMERA_LOG_H_
#define CAMERA_LOG_H_

#include "rm_log.h"
#include <string>

// 生命周期覆盖整个 main，保证提前返回时也刷新并关闭异步日志。
class CameraLogSession {
public:
    explicit CameraLogSession(const std::string &program) {
        INIT_LOG("logs/" + program + ".log", "debug", "debug", "debug");
        RM_LOG_DEBUG("日志初始化完成");
    }
    ~CameraLogSession() {
        utils::RMLOG::instance().getLogger()->flush();
        utils::RMLOG::instance().Close();
    }
    CameraLogSession(const CameraLogSession &) = delete;
    CameraLogSession &operator=(const CameraLogSession &) = delete;
};

#endif // CAMERA_LOG_H_
