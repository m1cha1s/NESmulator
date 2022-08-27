cmake_minimum_required(VERSION 3.10)

project(NESmulator)

# Find all .c files
FILE(GLOB Sources src/*.c)

add_executable(NESmulator ${Sources})