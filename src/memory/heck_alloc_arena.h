#ifndef HECK_ALLOC_ARENA_H
#define HECK_ALLOC_ARENA_H

#include "heck_alloc_common.h"

#include <stddef.h>

HECK_alloc* HECK_alloc_arena_new(void* buffer, size_t buffer_size);
void* HECK_alloc_arena_alloc(HECK_alloc* alloc, size_t size);
void HECK_alloc_arena_free(HECK_alloc* alloc, void* ptr);
void HECK_alloc_arena_free_all(HECK_alloc* alloc);
void HECK_alloc_arena_release(HECK_alloc* alloc);

#endif // #ifndef HECK_ALLOC_ARENA_H

