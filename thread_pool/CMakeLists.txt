set(THREADPOOL_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/thread_pool" CACHE STRING "ThreadPool library include path")
set(THREADPOOL_LIB_NAME "threadpool" CACHE STRING "ThreadPool library name")


add_library(threadpool SHARED thread_pool.cpp joining_threads.cpp function_wrapper.cpp)
add_library(threadpool_static STATIC thread_pool.cpp joining_threads.cpp function_wrapper.cpp)
