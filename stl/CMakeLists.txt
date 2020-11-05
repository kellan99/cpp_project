file(GLOB src_files 
./*.cpp)

add_library(libstl SHARED ${src_files})