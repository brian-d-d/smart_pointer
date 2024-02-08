cmake_minimum_required(VERSION 3.15)
project(implement_smartptr)
set(CMAKE_CXX_STANDARD 23)

add_library(MyShared_Ptr myshared_ptr.cpp)

add_library(GTestMain SHARED IMPORTED)
set_target_properties(GTestMain PROPERTIES IMPORTED_LOCATION /usr/local/lib/libgtest_main.a)

add_library(GTest SHARED IMPORTED)
set_target_properties(GTest PROPERTIES IMPORTED_LOCATION /usr/local/lib/libgtest.a)

add_library(GMock SHARED IMPORTED)
set_target_properties(GMock PROPERTIES IMPORTED_LOCATION /usr/local/lib/libgmock.a)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC MyShared_Ptr)
target_link_libraries(main PUBLIC GTestMain)
target_link_libraries(main PUBLIC GTest)
target_link_libraries(main PUBLIC GMock)

install(TARGETS main DESTINATION ${PROJECT_BINARY_DIR}/..)

include_directories(/usr/local/include/)








