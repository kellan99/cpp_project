file(GLOB src_files 
./*.cpp)

add_library(librtti SHARED ${src_files})