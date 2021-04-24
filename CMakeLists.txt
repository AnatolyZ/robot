cmake_minimum_required(VERSION 3.5)

project(robot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(robot main.cpp)
target_link_libraries(robot -static-libgcc -static-libstdc++)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/robot DESTINATION ${DEPLOY_PREFIX})


