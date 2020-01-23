cmake_minimum_required(VERSION 3.1)

project(DiskCache)

option(${PROJECT_NAME}_BUILD_EXAMPLE "" ON)

# log
include_directories(modules/LOG)

# common
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall)

# project
file(GLOB SRCS *.c*)
add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC .)

# example
if(${PROJECT_NAME}_BUILD_EXAMPLE)
    link_libraries(${PROJECT_NAME})
    add_executable(${PROJECT_NAME}_example example.cpp)
endif()
