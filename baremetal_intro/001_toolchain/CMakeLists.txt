cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME 001_desktop)
project(${PROJECT_NAME} C)

set(SOURCES
    main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

