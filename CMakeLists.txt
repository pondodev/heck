cmake_minimum_required(VERSION 3.11)
include(FetchContent)

project             (heck VERSION 0.1 LANGUAGES C)
set                 (CMAKE_C_STANDARD 17)
add_compile_options (-Wall -Wextra -pedantic)

include(options.cmake)

# check if we've been included as a dependency or not
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(HECK_IS_MAIN TRUE)
else()
    set(HECK_IS_MAIN FALSE)
endif()

if (HECK_IS_MAIN)
    # only need compilation db if we're actively working on the project
    set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

    if (HECK_ENABLE_TESTS)
        include(CTest)

        FetchContent_Declare(
            unity
            GIT_REPOSITORY  https://github.com/ThrowTheSwitch/Unity.git
            GIT_TAG         v2.5.2
        )
        message(STATUS "fetching unity...")
        FetchContent_MakeAvailable(Unity) # wait until we have unity downloaded
        message(STATUS "done!")
    endif()
endif()

# add the library code
add_subdirectory(src ${PROJECT_NAME})

# add tests to build
if (HECK_IS_MAIN AND HECK_ENABLE_TESTS)
    include(unit_tests.cmake)
endif()

