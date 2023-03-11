cmake_minimum_required(VERSION 3.0)

project(SLAE)

enable_testing()

include_directories(source)

add_subdirectory(source)
add_subdirectory(tests)
add_subdirectory(graphs)