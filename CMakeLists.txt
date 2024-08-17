cmake_minimum_required(VERSION 3.10)
project(lazywm)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIR})

add_executable(lazywm
    src/main.cpp
    src/window_manager.cpp
    src/config_manager.cpp
    src/event_bus.cpp
    src/input_manager.cpp
    src/compositor.cpp
    src/ipc_manager.cpp
    src/log_manager.cpp
    src/monitor_manager.cpp
    src/plugin_manager.cpp
    src/session_manager.cpp
    src/state_store.cpp
    src/window_layout_manager.cpp
    src/workspace_manager.cpp
)

target_link_libraries(lazywm ${X11_LIBRARIES})

add_custom_target(run
    DEPENDS lazywm
    COMMAND Xephyr -screen 1280x720 :1 &
    COMMAND sleep 1
    COMMAND DISPLAY=:1 ./lazywm
    COMMAND killall Xephyr
    COMMENT "Running lazywm"
)

