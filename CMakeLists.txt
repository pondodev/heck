cmake_minimum_required(VERSION 3.11)

#### project config ####

project             (heck VERSION 0.1)
set                 (CMAKE_C_STANDARD 17)
add_compile_options (-Wall -Wextra -pedantic)

set     (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# check if we've been included as a dependency or not
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(HECK_IS_MAIN TRUE)
else()
    set(HECK_IS_MAIN FALSE)
endif()

if (HECK_IS_MAIN)
    # only need compilation db if we're actively working on the project
    set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
endif()

#### project files ####

file    (GLOB_RECURSE HECK_CORE_LIB_SOURCES src/*.c)
set     (HECK_CORE_LIB_INCLUDE src/)

# TODO: optional modules
set     (HECK_LIB_SOURCES ${HECK_CORE_LIB_SOURCES})
set     (HECK_LIB_INCLUDE ${HECK_CORE_LIB_INCLUDE})

#### targets ####

add_library             (${PROJECT_NAME} ${HECK_LIB_SOURCES})

