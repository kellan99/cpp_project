file(GLOB src_files 
./*.cpp)

add_library(libcommon_ SHARED ${src_files})