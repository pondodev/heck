#ifndef HECK_ALLOC_COMMON_H
#define HECK_ALLOC_COMMON_H

/**
 * @file    heck_alloc_common.h
 * @brief   common types used among all allocators
 * @author  dan coady
 */

typedef enum {
    kHECK_alloc_arena,
    kHECK_alloc_stack,
    kHECK_alloc_pool,
    kHECK_alloc_freelist,
    kHECK_alloc_buddy,
} HECK_alloc_type;

/**
 * @brief   the base struct for all allocators, acts as your
 *          reference to a retrieved allocator
 */
typedef struct {
    HECK_alloc_type type;
} HECK_alloc;

#endif // #ifndef HECK_ALLOC_COMMON_H

