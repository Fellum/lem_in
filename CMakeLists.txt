cmake_minimum_required(VERSION 3.14)
project(lem-in C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(libft/include)
add_subdirectory(libft)

aux_source_directory(src srcs)

add_executable(lem-in ${srcs})

target_link_libraries(lem-in libft)