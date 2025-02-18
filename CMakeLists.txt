cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

project(minecraft_clock C CXX ASM)

pico_sdk_init()

add_subdirectory(./lib/Config)
add_subdirectory(./lib/LCD)
add_subdirectory(./lib/Fonts)
add_subdirectory(./lib/GUI)
add_subdirectory(./lib/QMI8658)
add_subdirectory(./examples)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/time_faces)
include_directories(./examples)
include_directories(./lib/Config)
include_directories(./lib/Fonts)
include_directories(./lib/GUI)
include_directories(./lib/LCD)
include_directories(./lib/QMI8658)

add_executable(minecraft_clock 
main.c
time_faces/color.h
time_faces/time_one.h
time_faces/time_one.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(minecraft_clock 1)
pico_enable_stdio_uart(minecraft_clock 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(minecraft_clock)

target_link_libraries(minecraft_clock examples LCD QMI8658 GUI Fonts Config pico_stdlib hardware_spi hardware_i2c)