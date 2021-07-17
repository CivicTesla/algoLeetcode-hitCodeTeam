cmake_minimum_required(VERSION 3.0)  # cmake -G "MinGW Makefiles" ..
project(GTESTWIN)

# ------编译函数方法，指定.h文件和.cpp文件路
# 头文件目录
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/include")
# 源文件目录
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/src/src" DIR_SRCS)
# ------编译函数方法结束

#-----------生成可执行文件
# 生成可执行文件，一行命令一个
add_executable(gtest_m-swap_win ./src/m-swap.cpp ${DIR_SRCS})
add_executable(gtest_m-add_win ./src/m-add.cpp ${DIR_SRCS})

# 一次批量生成多个可执行文件.exe的命令，原理：获取本文件所在目录的src文件夹下的.cpp文件，并以相同文件命名
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/src/m-*.cpp")# /*.cpp表示该目录下的所有m-开头的.cpp文件，包含子目录;//? 如何仅表示一级目录
foreach(mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile} ${DIR_SRCS})
endforeach()
#-----------生成可执行文件结束

# 增加测试工程;把测试代码作为源码的子工程添加到源码中，测试代码的CMake工程为gtes_win/test文件夹;! 生成的程序将出现在编译目录build下的test文件夹中
# 若不需要测试，将下面的代码注释掉即可
add_subdirectory(test)