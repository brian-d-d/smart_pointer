cmake_minimum_required(VERSION 3.15)
project(implement_smartptr)
set(CMAKE_CXX_STANDARD 11)

add_library(MySmart PUBLIC myshared_ptr.cpp)

add_executable(Main main.cpp)
target_link_libraries(Main PUBLIC MyGTest)
install(TARGETS Main DESTINATION ${PROJECT_BINARY_DIR}/..)






