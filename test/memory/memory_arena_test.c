#include "memory_arena_test.h"

#include "unity.h"
#include "heck_alloc.h"

#include <stddef.h>
#include <string.h>

void TEST_get_arena(void) {
    #define BUFFER_SIZE 100
    unsigned char buffer[BUFFER_SIZE];
    HECK_alloc* alloc = HECK_alloc_new(kHECK_alloc_arena, buffer, BUFFER_SIZE);

    TEST_ASSERT_NOT_NULL_MESSAGE(alloc, "failed to get arena allocator");
}

void TEST_arena_alloc(void) {
    #define BUFFER_SIZE 100
    unsigned char buffer[BUFFER_SIZE];
    HECK_alloc* alloc = HECK_alloc_new(kHECK_alloc_arena, buffer, BUFFER_SIZE);

    #define TEMP_BUFFER_SIZE 5
    unsigned char* temp_buffer = HECK_alloc_alloc(alloc, TEMP_BUFFER_SIZE);

    TEST_ASSERT_NOT_NULL_MESSAGE(temp_buffer, "pointer to allocated memory is NULL");

    #define FUNNY_NUMBER 69
    memset(temp_buffer, FUNNY_NUMBER, TEMP_BUFFER_SIZE);
    for (size_t i = 0; i < TEMP_BUFFER_SIZE; ++i) {
        TEST_ASSERT_EQUAL_UINT8_MESSAGE(FUNNY_NUMBER, buffer[i], "arena did not correctly allocate memory within the buffer");
    }
}

void TEST_arena_free_all(void) {
    #define BUFFER_SIZE 100
    unsigned char buffer[BUFFER_SIZE];
    HECK_alloc* alloc = HECK_alloc_new(kHECK_alloc_arena, buffer, BUFFER_SIZE);

    #define TEMP_BUFFER_SIZE 5
    unsigned char* temp_buffer = HECK_alloc_alloc(alloc, TEMP_BUFFER_SIZE);

    TEST_ASSERT_NOT_NULL_MESSAGE(temp_buffer, "pointer to allocated memory is NULL");

    memset(temp_buffer, 69, TEMP_BUFFER_SIZE);
    HECK_alloc_free_all(alloc);
    for (size_t i = 0; i < BUFFER_SIZE; ++i) {
        TEST_ASSERT_EQUAL_UINT8_MESSAGE(0, buffer[i], "arena did not correctly clear buffer");
    }
}

