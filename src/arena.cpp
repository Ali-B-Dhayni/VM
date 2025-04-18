#include <iostream>
#include <cstdint>
#include <cstdlib>
#include "arena.hpp"

#define CAPACITY 1024

struct Entity
{
	size_t size;
	void* data;
};

struct Arena
{
	size_t capacity;
	size_t size;
	uint8_t* data;
	Arena* next;
};

void*
custom_malloc(size_t size)
{
	void* ptr = malloc(sizeof(uint8_t) * size);

	if(ptr == nullptr) {
		std::cerr
		<< "ERROR: Failed to allocate requested memory segment."
		<< std::endl;
		exit(1);
	}
	return ptr;
}

Arena 
arena_init(size_t capacity)
{
	uint8_t* data = (uint8_t*) custom_malloc(sizeof(uint8_t) * capacity);

	Arena arena = {
		.capacity = capacity,
		.size = 0,
		.data = data,
		.next = nullptr,
	};

	return arena;
}

void
arena_reset(Arena* arena)
{
	while(arena != nullptr) {
		arena->size = 0;			
		arena = arena->next;
	}
}

void 
arena_free(Arena* arena)
{
	Arena* current = arena->next;

	free(arena->data);
	arena->capacity = 0;
	arena->size = 0;

	while(current != nullptr) {
		Arena* tmp = current->next;	
		free(current->data);
		free(current);
		current = tmp;
	}
	arena->next = nullptr;
}

void
arena_log (const Arena* arena)
{
	while(arena != nullptr){
		std::cout
		<< "Arena {\n" << "  .Size: " << arena->size << "\n  .Capacity: " 
		<< arena->capacity
		<< "\n}\n";

		arena = arena->next;
	}
}

void* 
arena_alloc(Arena* arena, size_t size)
{
	void* data;
	Arena* current = arena;

	while(current != nullptr) {
		if(current->size + size <= current->capacity){
			data = &(current->data[current->size]);
			current->size += size;
			return data;
		}
		current = arena->next;
	}

	Arena region = arena_init(1024);
	region.size += size;
	arena->next = (Arena*)custom_malloc(sizeof(Arena));

	(size > CAPACITY) ?
		region.capacity = size :
		region.capacity = CAPACITY;

	*(arena->next) = region;
	data = &(region.data[region.size]);
	return data;

	data = &((arena->data)[arena->size]);
	arena->size += size;

	return data;
}
