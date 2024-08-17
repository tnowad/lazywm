cmake_minimum_required(VERSION 3.10)
project(lazywm)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIR})

add_executable(lazywm
    src/main.cpp
    src/window_manager.cpp
    src/window_manager.h
    src/config_manager.cpp
    src/config_manager.h
    src/event_bus.cpp
    src/event_bus.h
    src/input_manager.cpp
    src/input_manager.h
    src/compositor.cpp
    src/compositor.h
    src/ipc_manager.cpp
    src/ipc_manager.h
    src/log_manager.cpp
    src/log_manager.h
    src/monitor_manager.cpp
    src/monitor_manager.h
    src/plugin_manager.cpp
    src/plugin_manager.h
    src/session_manager.cpp
    src/session_manager.h
    src/state_store.cpp
    src/state_store.h
    src/window_layout_manager.cpp
    src/window_layout_manager.h
    src/workspace_manager.cpp
    src/workspace_manager.h
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

