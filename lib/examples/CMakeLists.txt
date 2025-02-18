# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_examples_SRCS 变量
aux_source_directory(. DIR_examples_SRCS)

include_directories(../Config)
include_directories(../GUI)
include_directories(../LCD)
include_directories(../QMI8658)
# 生成链接库
add_library(examples ${DIR_examples_SRCS})
target_link_libraries(examples PUBLIC Config LCD QMI8658 hardware_clocks hardware_rtc hardware_adc)