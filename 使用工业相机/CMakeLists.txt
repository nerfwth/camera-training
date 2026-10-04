cmake_minimum_required(VERSION 3.11)
project(camera_demo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

set(MVS_ROOT "/opt/MVS")
if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    set(MVS_LIB "${MVS_ROOT}/lib/aarch64/libMvCameraControl.so")
else()
    set(MVS_LIB "${MVS_ROOT}/lib/64/libMvCameraControl.so")
endif()

add_executable(video_demo video_demo.cpp)
target_include_directories(video_demo PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(video_demo ${OpenCV_LIBS})

add_executable(daheng_demo daheng_demo.cpp)
target_include_directories(daheng_demo PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/include"
    ${OpenCV_INCLUDE_DIRS})
target_link_libraries(daheng_demo ${OpenCV_LIBS} gxiapi)

add_executable(daheng_test daheng_test.cpp)
target_include_directories(daheng_test PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/include"
    ${OpenCV_INCLUDE_DIRS})
target_link_libraries(daheng_test ${OpenCV_LIBS} gxiapi)

# rm_log 使用 spdlog，同时输出到终端和文件。
set(RM_LOG_UTIL "${CMAKE_CURRENT_LIST_DIR}/../使用日志库/util")
foreach(target video_demo daheng_demo daheng_test)
    target_sources(${target} PRIVATE "${RM_LOG_UTIL}/rm_log/src/rm_log.cpp")
    target_include_directories(${target} PRIVATE
        "${RM_LOG_UTIL}"
        "${RM_LOG_UTIL}/rm_log/include"
        # 兼容现有日志库目录的拼写。
        "${RM_LOG_UTIL}/rm_log/inlcude")
    target_link_libraries(${target} Threads::Threads)
endforeach()
