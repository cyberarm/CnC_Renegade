cmake_minimum_required(VERSION 3.26)

project(commando_engine)
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG REQUIRED COMPONENTS SDL3_image-shared)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(commando_engine src/commando_engine.cpp src/window.cpp)

target_link_libraries(commando_engine PRIVATE SDL3_image::SDL3_image SDL3::SDL3)
