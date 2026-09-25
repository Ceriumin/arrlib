#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void * array_at(void *arr, size_t element_size, size_t length, signed int index){
    unsigned char *bytes = (unsigned char *) arr;
    if(index < 0) index = (length + index);
    
    return (void *) ((size_t) bytes + index * element_size);
}

int main(void){
    int arr[8] = { 2, 5, 9, 0, 3, 4, 5, 1};

    printf("%d\n", *(int *) array_at(arr, sizeof(int), 8, 1));
    return 0;
}
