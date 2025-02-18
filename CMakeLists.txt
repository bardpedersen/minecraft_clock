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
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/time_faces/header)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/time_faces/src)
include_directories(./examples)
include_directories(./lib/Config)
include_directories(./lib/Fonts)
include_directories(./lib/GUI)
include_directories(./lib/LCD)
include_directories(./lib/QMI8658)

add_executable(minecraft_clock 
main.c
time_faces/src/time_1.c
time_faces/src/time_2.c
time_faces/src/time_3.c
time_faces/src/time_4.c
time_faces/src/time_5.c
time_faces/src/time_6.c
time_faces/src/time_7.c
time_faces/src/time_8.c
time_faces/src/time_9.c
time_faces/src/time_10.c
time_faces/src/time_11.c
time_faces/src/time_12.c
time_faces/src/time_13.c
time_faces/src/time_14.c
time_faces/src/time_15.c
time_faces/src/time_16.c
time_faces/src/time_17.c
time_faces/src/time_18.c
time_faces/src/time_19.c
time_faces/src/time_20.c
time_faces/src/time_21.c
time_faces/src/time_22.c
time_faces/src/time_23.c
time_faces/src/time_24.c
time_faces/src/time_25.c
time_faces/src/time_26.c
time_faces/src/time_27.c
time_faces/src/time_28.c
time_faces/src/time_29.c
time_faces/src/time_30.c
time_faces/src/time_31.c
time_faces/src/time_32.c
time_faces/src/time_33.c
time_faces/src/time_34.c
time_faces/src/time_35.c
time_faces/src/time_36.c
time_faces/src/time_37.c
time_faces/src/time_38.c
time_faces/src/time_39.c
time_faces/src/time_40.c
time_faces/src/time_41.c
time_faces/src/time_42.c
time_faces/src/time_43.c
time_faces/src/time_44.c
time_faces/src/time_45.c
time_faces/src/time_46.c
time_faces/src/time_47.c
time_faces/src/time_48.c
time_faces/src/time_49.c
time_faces/src/time_50.c
time_faces/src/time_51.c
time_faces/src/time_52.c
time_faces/src/time_53.c
time_faces/src/time_54.c
time_faces/src/time_55.c
time_faces/src/time_56.c
time_faces/src/time_57.c
time_faces/src/time_58.c
time_faces/src/time_59.c
time_faces/src/time_60.c
time_faces/src/time_61.c
time_faces/src/time_62.c
time_faces/src/time_63.c
time_faces/src/time_64.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(minecraft_clock 1)
pico_enable_stdio_uart(minecraft_clock 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(minecraft_clock)

target_link_libraries(minecraft_clock examples LCD QMI8658 GUI Fonts Config pico_stdlib hardware_spi hardware_i2c)