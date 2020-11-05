cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=gnu++11)

project(CPP_PROJECT)

add_subdirectory(./rtti)
add_subdirectory(./intel_ptr)

add_executable(main ./main.cpp)
target_link_libraries(main librtti libintel_ptr)