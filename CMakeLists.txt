cmake_minimum_required(VERSION 3.0)

project(AP)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(todo src/main.cpp src/Icon.cpp src/ToDo.cpp 
                 src/Task.cpp src/AddButton.cpp
                 src/Vector.cpp src/EditButton.cpp 
                 src/Button.cpp src/Set.cpp 
                 src/File.cpp )

target_link_libraries(todo sfml-window sfml-system sfml-graphics)