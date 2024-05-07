cmake_minimum_required(VERSION 3.12) 
project(dna VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")
include (prevent_source_builds)
include (clang_tidy)

include_directories(include)

add_executable(${PROJECT_NAME} 
  main.cpp
  command_processor.cpp
  fragment_list.cpp
  sequence_fragment.cpp
)

file (COPY 
      DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
      FILES_MATCHING PATTERN commands*.txt)

