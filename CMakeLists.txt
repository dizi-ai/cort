cmake_minimum_required(VERSION 3.20)
project(cort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cort
        tests/01-basic_ops.cort
        tests/02-bool_ops.cort
        cort.cpp
        if_loops.h
        operations.h
        operations_imp.h
        read_file.h
        )
