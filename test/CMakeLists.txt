# 禁用默认cmake行为，防止找不到BoostConfig.cmake
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()
find_package(Boost REQUIRED COMPONENTS regex)

# lambda示例
add_executable(lambda lambda.cpp)
target_link_libraries(lambda Boost::headers)

# 正则表示式示例
add_executable(regex regex.cpp)
target_link_libraries(regex Boost::regex)
