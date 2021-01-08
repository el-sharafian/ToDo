cmake_minimum_required(VERSION 3.0)

project(AP)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(todo src/main.cpp src/start.cpp)

target_link_libraries(todo sfml-window sfml-system sfml-graphics)