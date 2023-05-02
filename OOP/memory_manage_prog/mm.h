#define _GNU_SOURCE 
#define _MM_H 1

#include <stdio.h>
#include <stdlib.h>

// TODO include header files 
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdbool.h>

// TODO define structure for memory informaiton  
typedef struct MEM{
    struct MEM *next;
    size_t mem_size;
} node;

// TODO Function declaration  
void *mm_malloc(size_t size);
void *mm_calloc(size_t num, size_t size);
void *mm_realloc(void *ptr, size_t size);
void mm_free(void *ptr);
void mm_status();
