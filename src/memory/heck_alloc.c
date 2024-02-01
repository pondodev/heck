#include "heck_alloc.h"

#include "heck_alloc_arena.h"

HECK_alloc* HECK_alloc_new(HECK_alloc_type type, void* buffer, size_t buffer_size) {
    switch (type) {
        case kHECK_alloc_arena:
            return HECK_alloc_arena_new(buffer, buffer_size);
        case kHECK_alloc_stack:
        case kHECK_alloc_pool:
        case kHECK_alloc_freelist:
        case kHECK_alloc_buddy:
        default:
            return NULL;
    }
}

void* HECK_alloc_alloc(HECK_alloc* alloc, size_t size) {
    switch (alloc->type) {
        case kHECK_alloc_arena:
            return HECK_alloc_arena_alloc(alloc, size);
        case kHECK_alloc_stack:
        case kHECK_alloc_pool:
        case kHECK_alloc_freelist:
        case kHECK_alloc_buddy:
        default:
            return NULL;
    }
}

void HECK_alloc_free(HECK_alloc* alloc, void* ptr) {
    switch (alloc->type) {
        case kHECK_alloc_arena:
            HECK_alloc_arena_free(alloc, ptr);
            return;
        case kHECK_alloc_stack:
        case kHECK_alloc_pool:
        case kHECK_alloc_freelist:
        case kHECK_alloc_buddy:
        default:
            return;
    }
}

void HECK_alloc_free_all(HECK_alloc* alloc) {
    switch (alloc->type) {
        case kHECK_alloc_arena:
            HECK_alloc_arena_free_all(alloc);
            return;
        case kHECK_alloc_stack:
        case kHECK_alloc_pool:
        case kHECK_alloc_freelist:
        case kHECK_alloc_buddy:
        default:
            return;
    }
}

void HECK_alloc_release(HECK_alloc* alloc) {
    switch (alloc->type) {
        case kHECK_alloc_arena:
            HECK_alloc_arena_release(alloc);
            return;
        case kHECK_alloc_stack:
        case kHECK_alloc_pool:
        case kHECK_alloc_freelist:
        case kHECK_alloc_buddy:
        default:
            return;
    }
}

