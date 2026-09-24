#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void *array_at(void *input, size_t element_size, int idx){
    return (char *) input + idx * element_size;
}

//concat

//copywithin

//entries

int array_every(void *arr, size_t element_size, size_t length, int (* callback)(void *element)){
    for(size_t idx = 0; idx < length; idx++){
        if(callback((char *) arr + idx * element_size) == 1) return 1;
    }

    return 0;
}

void array_fill(void *arr, size_t element_size, size_t length, void *value, int start, int end){
    unsigned char *bytes = arr;

    if (start < 0)
        start = 0;

    if (end > (int)length)
        end = length;

    for (int idx = start; idx < end; idx++) {
        memcpy(bytes + idx * element_size, value, element_size);
    }
}

int main(void){
    int arr[5] = {3, 5, 1, 9, 4};
   

    return 0;
}
