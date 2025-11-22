cmake_minimum_required(VERSION 3.22)
project(C_ProgrammingExercise C)

set(CMAKE_C_STANDARD 99)

# 包含头文件目录
include_directories(src)

# 自动查找所有源文件
file(GLOB_RECURSE SOURCE_FILES "src/*.c")

# 创建可执行文件
add_executable(C_Programming_Practice ${SOURCE_FILES})