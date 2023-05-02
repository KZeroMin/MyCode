#define _GNU_SOURCE 
#define _MM_H 1
#include "mm.h"

int main()
{
    int* x = (int*) mm_malloc(sizeof(int));
    int* y = (int*) mm_malloc(sizeof(int));
    int* z = (int*) mm_malloc(sizeof(int));
    int* array = mm_calloc(sizeof(int), 10);

    printf("** Step #1 **\n");
    
    *x = 10; 
    *y = 20; 
    *z = *x + *y;
    
    printf("x + y = %d \n", *z);
    for (int i = 0; i < 10; i++)
    {
        array[i] = i * i;
        printf("array[%d] = %d \n", i, array[i]);
    }
    mm_status();

    printf("\n** Step #2 **\n");
    mm_realloc(y, sizeof(long));    
    *y = (long)50;
    *z = *x + *y; 
    printf("x + y = %d \n", *z);
    mm_status();   

    printf("\n** Step #3 **\n");
    mm_free(y); 
    mm_status();
    
    printf("\n** Step #4 **\n");
    mm_realloc(array, sizeof(int) * 12); 
    for (int i = 0; i < 12; i++)
    {
        if (i >= 10)
            *(array+i) = i*i;

        printf("array[%d] = %d \n", i, array[i]);
    }
    mm_status(); 

    return 0;
}