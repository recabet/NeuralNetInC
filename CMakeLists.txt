cmake_minimum_required(VERSION 3.29)
project(NeuralNetInC C)

set(CMAKE_C_STANDARD 11)

add_executable(NeuralNetInC main.c
        neural.h
        neural.c)
