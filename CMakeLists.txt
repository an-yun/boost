cmake_minimum_required(VERSION 3.8...3.31)
project(MyProject)
# 禁用默认cmake行为，防止找不到BoostConfig.cmake
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()
find_package(Boost REQUIRED)
add_executable(example example.cpp)
target_link_libraries(example Boost::headers)