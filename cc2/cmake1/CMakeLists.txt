cmake_minimum_required(VERSION 3.5)

project(Project)

set(SOURCES src/main.cpp src/funciones.cpp)
set(INCLUDES include)

add_executable(programa ${SOURCES})
add_library(biblioteca STATIC src/funciones.cpp)

target_include_directories(programa PRIVATE ${INCLUDES})
target_include_directories(biblioteca PUBLIC ${INCLUDES})

target_link_libraries(programa PRIVATE biblioteca)

