cmake_minimum_required(VERSION 3.0)

project(AP)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(todo src/main.cpp src/icon.cpp src/ToDo.cpp 
                 src/task.cpp src/AddButton.cpp
                 src/vector.cpp src/editButton.cpp 
                 src/Button.cpp src/set.cpp 
                 src/file.cpp )

target_link_libraries(todo sfml-window sfml-system sfml-graphics)