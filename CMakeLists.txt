cmake_minimum_required(VERSION 3.26)

project(commando_engine LANGUAGES CXX VERSION 0.1.0)
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG REQUIRED COMPONENTS SDL3_image-shared)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Code/combat)
#add_subdirectory(Code/Commando)
#add_subdirectory(Code/Scripts)
#add_subdirectory(Code/ww3d2)
#add_subdirectory(Code/WWAudio)
#add_subdirectory(Code/wwbitpack)
#add_subdirectory(Code/wwlib)
#add_subdirectory(Code/WWMath)
#add_subdirectory(Code/wwphys)
#add_subdirectory(Code/wwnet)
#add_subdirectory(Code/wwsaveload)
#add_subdirectory(Code/wwtranslatedb)
#add_subdirectory(Code/wwui)
#add_subdirectory(Code/wwutil)

include_directories(include)
add_executable(commando_engine src/commando_engine.cpp src/window.cpp)

target_link_libraries(commando_engine PRIVATE
        wwcombat_lib
        SDL3_image::SDL3_image
        SDL3::SDL3)
