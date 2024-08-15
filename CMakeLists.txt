cmake_minimum_required(VERSION 3.10)
project(lazywm)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIR})

add_executable(lazywm
    src/main.cpp
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

