cmake_minimum_required(VERSION 2.6)
project(C302 C)
SET(CMAKE_BUILD_TYPE "Release")

# include_directories("/usr/local/include")
# link_directories("/usr/local/lib")

#在编译选项中加入c99支持
add_compile_options(-std=c99)
message(STATUS "optional:-std=c99") 

add_executable(c302 c302.c)

INSTALL(TARGETS c302 RUNTIME DESTINATION bin)
