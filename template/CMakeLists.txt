file(GLOB src_files 
./*.cpp)

add_library(libtemplate SHARED ${src_files})