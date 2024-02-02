set (TEST_NAME ${PROJECT_NAME}_memory_arena_allocator_test)
set (TEST_SOURCES
     memory_arena_test_runner.c
     memory_arena_test.c)

add_executable          (${TEST_NAME} ${TEST_SOURCES})
target_link_libraries   (${TEST_NAME} ${PROJECT_NAME} unity)

add_test(${TEST_NAME} ${TEST_NAME})
