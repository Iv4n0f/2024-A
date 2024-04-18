cmake_minimum_required(VERSION 3.5)

project(Project)

add_executable(programa src/main.cpp src/funciones.cpp)
add_library(biblioteca STATIC src/funciones.cpp)

target_include_directories(programa PRIVATE include)
target_include_directories(biblioteca PUBLIC include)

target_link_libraries(programa PRIVATE biblioteca)

