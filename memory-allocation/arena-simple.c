#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned char *arena_buffer;
static size_t arena_buffer_size;
static size_t arena_offset;

void *arena_allocator(size_t size)
{
	if(arena_offset + size <= arena_buffer_size)
	{
		void* ptr = &arena_buffer[arena_offset];
		arena_offset += size;
		memset(ptr, 0, size);
		return ptr;
	}
	return NULL;
}
struct types
{
	int int_type;
	float float_type;
};

int main(void)
{
	int *inin;
	if(inin = arena_allocator(20) == NULL)
		fprintf(stderr, "arena full\n");

	
	//arena
	struct types *arena = malloc( (sizeof(struct types) ) * 100);
	arena[0].int_type = 12;
	arena[0].float_type = 24.21;

	arena[1].int_type = 14;
	arena[1].float_type = 15.16;
	


	exit(0);
}
