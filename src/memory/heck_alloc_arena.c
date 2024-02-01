#include "heck_alloc_arena.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARENA_COUNT 10

typedef struct {
    char            _padding[sizeof(HECK_alloc)]; // allow space for the base alloc struct data
    int             active;
    unsigned char*  buffer;
    size_t          buffer_size;
    size_t          offset;
} ArenaAllocator;

static ArenaAllocator s_allocators[MAX_ARENA_COUNT];

static void _init(void);
static ArenaAllocator* _get_alloc(HECK_alloc* alloc);
static void _clear_arena(ArenaAllocator* arena);

HECK_alloc* HECK_alloc_arena_new(void* buffer, size_t buffer_size) {
    _init();

    if (buffer == NULL || buffer_size == 0)
        return NULL;

    for (size_t i = 0; i < MAX_ARENA_COUNT; ++i) {
        ArenaAllocator* arena = &s_allocators[i];
        if (arena->active)
            continue;

        arena->active = 1;
        arena->buffer = buffer;
        arena->buffer_size = buffer_size;
        _clear_arena(arena);

        HECK_alloc* alloc = (HECK_alloc*)arena;
        alloc->type = kHECK_alloc_arena;
        return alloc;
    }

    return NULL;
}

void* HECK_alloc_arena_alloc(HECK_alloc* alloc, size_t size) {
    _init();
    ArenaAllocator* arena = _get_alloc(alloc);
    if (arena == NULL)
        return NULL;

    const size_t new_offset = arena->offset + size;
    // no space left in buffer
    if (new_offset > arena->buffer_size)
        return NULL;

    void* ptr = &arena->buffer[arena->buffer_size];
    arena->offset = new_offset;
    return ptr;
}

void HECK_alloc_arena_free(HECK_alloc* alloc, void* ptr) {
    _init();

    (void)alloc;
    (void)ptr;
    // NOP
}

void HECK_alloc_arena_free_all(HECK_alloc* alloc) {
    _init();

    ArenaAllocator* arena = _get_alloc(alloc);
    if (arena == NULL)
        return;

    _clear_arena(arena);
}

void HECK_alloc_arena_release(HECK_alloc* alloc) {
    _init();

    ArenaAllocator* arena = _get_alloc(alloc);
    if (arena == NULL)
        return;

    arena->active = 0;
}

static void _init(void) {
    static int s_initialised = 0;
    if (s_initialised)
        return;

    for (size_t i = 0; i < MAX_ARENA_COUNT; ++i) {
        s_allocators[i] = (ArenaAllocator) {
            .active = 0,
            .buffer = NULL,
            .buffer_size = 0,
            .offset = 0,
        };
    }

    s_initialised = 1;
}

static ArenaAllocator* _get_alloc(HECK_alloc* alloc) {
    const uintptr_t base_addr   = (uintptr_t)s_allocators;
    const uintptr_t end_addr    = (uintptr_t)s_allocators + MAX_ARENA_COUNT;
    const uintptr_t alloc_addr  = (uintptr_t)alloc;

    if (alloc_addr < base_addr || alloc_addr > end_addr)
        return NULL;

    ArenaAllocator* arena = (ArenaAllocator*)alloc;
    return arena->active ? arena : NULL;
}

static void _clear_arena(ArenaAllocator* arena) {
    arena->offset = 0;
    memset(arena->buffer, 0, arena->buffer_size);
}

