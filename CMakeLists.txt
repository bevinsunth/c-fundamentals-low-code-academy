cmake_minimum_required(VERSION 4.3)
project(c_fundamentals_low_code_academy C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(c_fundamentals_low_code_academy
        inc/kv.h
        src/kv.c
        main.c)
