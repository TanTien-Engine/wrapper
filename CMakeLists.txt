cmake_minimum_required(VERSION 3.16)

project(wrapper)

################################################################################
# Source groups
################################################################################

set(ALL_FILES
    "include/wrapper/Proxy.h"
    "include/wrapper/TransHelper.h"
    "include/wrapper/TransHelper.inl"
    "include/wrapper/Graph.h"
    "source/TransHelper.cpp"
    "source/Graph.cpp"
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
if(TARGET guard)
    target_link_libraries(${PROJECT_NAME} PRIVATE guard)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE external/guard/include)
endif()
if(TARGET vessel)
    target_link_libraries(${PROJECT_NAME} PRIVATE vessel)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE external/vessel/src/include)
endif()
if(TARGET sm)
    target_link_libraries(${PROJECT_NAME} PRIVATE sm)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE external/sm)
endif()
