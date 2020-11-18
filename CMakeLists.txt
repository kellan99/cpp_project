cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11 -g)

project(CPP_PROJECT)

add_subdirectory(./rtti)
add_subdirectory(./intel_ptr)
add_subdirectory(./stl)
add_subdirectory(./common)
add_subdirectory(./template)

add_executable(main ./main.cpp)
target_link_libraries(main librtti libintel_ptr libstl libcommon_ pthread libtemplate)