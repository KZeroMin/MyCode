#define _GNU_SOURCE
#define _MM_H 1

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdbool.h>

// Memory allocation structure
typedef struct MEM{
    struct MEM *next;
    size_t mem_size;
    int *ptr;
} Node;

int i = 0;
int nodeNum = 0;
int *add[4];
size_t s[4];
Node block[4];  // Structure array: to store memory information

// Similar to malloc() function, This function allocates size bytes and returns a pointer to the allocated memory
// This function adds a memory information to the memory allocation list
void *mm_malloc(size_t size){
    int *x = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);  // Allocate memory by size value
    block[i].ptr = x;
    block[i].mem_size = size;
    i++;

    if(nodeNum == 0){
        Node *head = mmap(NULL, sizeof(Node), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

        head->next = NULL;
    }
    Node *node = mmap(NULL, sizeof(Node), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    return x;
}

// Similar to colloc() function, This function allocates memory for an array of num elements of size bytes each and returns a pointer to the allocated memory
// This function also adds memory information to the memory allocation list
void *mm_calloc(size_t num, size_t size){
    int *x = mmap(NULL, num*size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0); // Allocate memory by size value
    block[i].ptr = x;
    block[i].mem_size = num*size;
    i++;
    return x;
}

// This function change the size of the memory block pointed to by ptr to size bytes
// Thi functions modifies the corresponding memory informaiton in the memory allocation list
void *mm_realloc(void *ptr, size_t size){   // Reallocate memory for address value ptr by 'size' size
    for(int i=0; i<4; i++){
        if(block[i].ptr == ptr){
            int *x = mremap(ptr, block[i].mem_size, size, 0);
            block[i].ptr = x;
            block[i].mem_size = size;
        }
    }
}

// Similar to free() fuction, This function frees the memory space pointed to by ptr, which must have been returned by a privious call to mm_malloc(), mm_colloc(), or mm_realloc()
// This function removes corresponding memory informatoin from the memory allocation list
void mm_free(void *ptr){
    for(int i=0; i<4; i++){
        if(block[i].ptr == ptr){
            int a = munmap(ptr, block[i].mem_size); // Release memory allocated to address value ptr
            if(a == 0){
                block[i].ptr = 0;
                block[i].mem_size = 0;
            }

        }
    }
}

// This function prints the address and size of allocated memory by traversing the memory allocatoin list
void mm_status(){
    printf("Allocated Memory:\n");
    int num = 0;
    for(int i = 0; i < 4; i++){
        if(block[i].mem_size == 0 || block[i].ptr == 0){

        }
        else{
            printf("[  %d] Addr=%p, Size=%lu\n", num,block[i].ptr, block[i].mem_size);
            num++;
        }
    }
    num = 0;

}