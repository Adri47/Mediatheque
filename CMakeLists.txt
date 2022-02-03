cmake_minimum_required(VERSION 2.8)
project(ProjetSimpleCMake)
include_directories(
    ${PROJECT_SOURCE_DIR}/Inc
    ${PROJECT_SOURCE_DIR}/Src
)
file(GLOB_RECURSE SRC_FILES 
    "${PROJECT_SOURCE_DIR}/Inc/*h"
    "${PROJECT_SOURCE_DIR}/Src/*cpp"
)
add_executable(Project ${SRC_FILES})