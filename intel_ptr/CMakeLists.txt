file(GLOB src_files 
./*.cpp)

add_compile_options(-std=c++14)

include_directories(../)

add_library(libintel_ptr SHARED ${src_files})
target_link_libraries(libintel_ptr librtti)