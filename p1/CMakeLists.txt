cmake_minimum_required(VERSION 3.27)
project(p1)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(p1
        src/book.cpp
        src/fileManagement.cpp
        main.cpp)

target_compile_options(p1 PRIVATE -Weverything -Wno-c++98-compat -Wall)