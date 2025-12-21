cmake_minimum_required(VERSION 3.16)

project(wrapper)

################################################################################
# Source groups
################################################################################

set(ALL_FILES
    "include/wrapper/Proxy.h"
    "include/wrapper/TransHelper.h"
    "include/wrapper/TransHelper.inl"
    "source/TransHelper.cpp"
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include external/guard/include external/vessel/src/include external/sm)
