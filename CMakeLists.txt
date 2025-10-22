cmake_minimum_required(VERSION 3.10)
project(TareaDiscretas C)

set(CMAKE_C_STANDARD 11)

add_executable(path
        src/main.c
        src/funciones.c
        src/LoadGraph.c
)