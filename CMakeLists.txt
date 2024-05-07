cmake_minimum_required(VERSION 3.12)

project(project-dna VERSION 1.0.0 LANGUAGES CXX)
include ("../common.cmake")

add_subdirectory(src)

add_executable(${PROJECT_NAME}
    main.cpp
    command_processor.cpp
    command_processor.h
    fragment_list.cpp
    fragment_list.h
    sequence_fragment.cpp
    sequence_fragment.h
)