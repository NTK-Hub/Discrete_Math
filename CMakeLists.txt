cmake_minimum_required(VERSION 3.26)
project(Discrete_Math C)

set(CMAKE_C_STANDARD 23)

add_executable(Discrete_Math main.c
        libs/alg/labs/lab3_1/lab3_1.c)

add_executable(lab3_1 labs/lab3_1/main.c libs/alg/labs/lab3_1/lab3_1.c)
