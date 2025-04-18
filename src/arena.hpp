#pragma once

#include <cstdint>

#define DEFAULT_SIZE 0;
#define DEFAULT_CAPACITY 1024;

Arena arena_init(size_t);
void arena_reset(Arena*);
void arena_log(Arena*);
void arena_free(Arena*);
void* arena_alloc(Arena*, size_t);
void* custom_malloc(size_t);
