cmake_minimum_required(VERSION 3.10)

project(NESmulator)

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src/)

add_subdirectory(cpu6502mulator)
add_subdirectory(memmulator)
target_link_libraries(NESmulator PRIVATE cpu6502mulator memmulator)