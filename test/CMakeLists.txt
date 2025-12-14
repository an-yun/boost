# 禁用默认cmake行为，防止找不到BoostConfig.cmake
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()
find_package(Boost REQUIRED COMPONENTS regex)
execute_process(
        COMMAND echo
        COMMAND bash -c "g++ -E -Wp,-v - 2>&1"
        COMMAND awk "/^#include .* starts here:$/,/^End of search list/ { if ($0 ~ /^ /) { print } }"
        OUTPUT_VARIABLE SYS_INCLUDES_OUT)
message("${SYS_INCLUDES_OUT}")
# lambda示例
add_executable(lambda lambda.cpp)
target_link_libraries(lambda Boost::headers)

# 正则表示式示例
add_executable(regex regex.cpp)
target_link_libraries(regex Boost::regex)

# bug正则表示式
add_executable(regex_bug regex_bug.cpp)
target_link_libraries(regex_bug Boost::regex)

add_library(macro_pod)

target_sources(macro_pod
        PRIVATE
        do_nothing.cpp
        PUBLIC
        FILE_SET HEADERS
        FILES
        macro_pod.hpp
)
# 复现内存布局导致的bug
add_executable(vector_insert)

target_sources(vector_insert
        PRIVATE
        vector_insert.cpp
)
target_link_libraries(vector_insert
        PRIVATE
        macro_pod
)
