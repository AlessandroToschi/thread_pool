cmake_minimum_required(VERSION 3.0.0)
project(thread_pool_project VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -mtune=native")

add_subdirectory(thread_pool)

add_executable(thread_pool_exe main.cpp)

target_link_libraries(thread_pool_exe PUBLIC "${THREADPOOL_LIB_NAME}")

target_include_directories(thread_pool_exe PUBLIC 
                           "${PROJECT_BINARY_DIR}" 
                           "${THREADPOOL_INCLUDE_PATH}"
                          )