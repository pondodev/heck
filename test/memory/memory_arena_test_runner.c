#include "unity.h"
#include "memory_arena_test.h"

void setUp(void) {
    // NOP
}

void tearDown(void) {
    // NOP
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(TEST_get_arena);
    RUN_TEST(TEST_arena_alloc);
    RUN_TEST(TEST_arena_free_all);

    return UNITY_END();
}

