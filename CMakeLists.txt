cmake_minimum_required(VERSION 3.13)
project(my_embedded_project LANGUAGES C)

set(SOURCES
    src/main.c
    src/hal.c
    src/ins_processor.c
    src/control.c
)

add_executable(my_embedded_project ${SOURCES})
