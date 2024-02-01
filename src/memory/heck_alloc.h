#ifndef HECK_ALLOC_H
#define HECK_ALLOC_H

/**
 * @file    heck_alloc.h
 * @brief   interface for memory management
 * @author  dan coady
 */

#include "heck_alloc_common.h"

#include <stddef.h>

/**
 * @brief get a new allocator of a given type
 *
 * @param [in] type         the type of the allocator to create
 * @param [in] buffer       the buffer to use for backing the allocator
 * @param [in] buffer_size  the size of `buffer`
 *
 * @retval HECK_alloc*      pointer to the requested allocator. is `NULL` if
 *                          a new allocator couldn't be created.
 */
HECK_alloc* HECK_alloc_new(HECK_alloc_type type, void* buffer, size_t buffer_size);

/**
 * @brief allocate a block of memory
 *
 * @param [in] alloc    pointer to the allocator to be used
 * @param [in] size     size in bytes to be allocated
 *
 * @retval void*        pointer to the requested block of memory. is `NULL`
 *                      if the allocator doesn't have enough space.
 */
void* HECK_alloc_alloc(HECK_alloc* alloc, size_t size);

/**
 * @brief free a given block of memory
 *
 * @param [in] alloc    pointer to the allocator to be used
 * @param [in] ptr      pointer to the memory to be freed. must have been
 *                      allocated with `alloc`!
 */
void HECK_alloc_free(HECK_alloc* alloc, void* ptr);

/**
 * @brief frees all memory managed by the allocator
 *
 * @param [in] alloc    pointer to the allocator to be used
 */
void HECK_alloc_free_all(HECK_alloc* alloc);

/**
 * @brief releases an allocator, making it invalid
 *
 * @param [in] alloc    pointer to the allocator to be released
 */
void HECK_alloc_release(HECK_alloc* alloc);

#endif // #ifndef HECK_ALLOC_H

