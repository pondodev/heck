# memory module files
file    (GLOB_RECURSE HECK_MODULE_MEMORY_SOURCES memory/*.c)
set     (HECK_MODULE_MEMORY_PUBLIC_HEADERS
         memory/heck_alloc.h
         memory/heck_alloc_common.h)

function(add_heck_module FLAG MODULE_SOURCES MODULE_PUBLIC_HEADERS)
    if (NOT FLAG)
        return()
    endif()

    set(HECK_LIB_SOURCES ${HECK_LIB_SOURCES} ${MODULE_SOURCES} PARENT_SCOPE)
    set(HECK_PUBLIC_HEADERS ${HECK_PUBLIC_HEADERS} ${MODULE_PUBLIC_HEADERS} PARENT_SCOPE)
endfunction()

add_heck_module(${HECK_MODULE_MEMORY}
                "${HECK_MODULE_MEMORY_SOURCES}"
                "${HECK_MODULE_MEMORY_PUBLIC_HEADERS}")

set(HECK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library             (${PROJECT_NAME} STATIC)
set_target_properties   (${PROJECT_NAME} PROPERTIES
                         VERSION ${PROJECT_VERSION})

file(COPY ${HECK_PUBLIC_HEADERS} DESTINATION include)

target_sources(${PROJECT_NAME}
               PRIVATE ${HECK_LIB_SOURCES})

           message("${CMAKE_CURRENT_BINARY_DIR}")
target_include_directories(${PROJECT_NAME}
                           INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/include
                           PRIVATE ${HECK_INCLUDE_DIR})

