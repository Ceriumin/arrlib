#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void * array_at(const void *arr, const size_t element_size, const size_t length, signed int index){
    unsigned char *bytes = (unsigned char *) arr;
    if(index < 0) index = (length + index);
    
    return (void *) ((size_t) bytes + index * element_size);
}

// void * concat(){};

// void * copyWithin(){};

// void * entries(){};

int array_every(const void *arr, const size_t element_size, const size_t length, int callback(void * element)){
    unsigned char * bytes = (unsigned char *) arr; 

    for(size_t idx = 0; idx < length; idx++){
        if(callback(bytes + idx * element_size) == 1){
           return 1; 
        }
    }

    return 0;
}

void *array_fill(void *arr, const size_t element_size, const size_t length, const void *val, size_t start, size_t end){
    unsigned char * bytes = (unsigned char*) arr;

    if(start < 0 || start >= end) 
        start = 0;
    if(end > length || end < start) 
        end = (int) length;

    for(size_t idx = start; idx < end; idx++){
        memcpy(bytes + idx * element_size, val, element_size);
    }
    
    return arr;
}

int main(void){
    int arr[8] = { 2, 5, 9, 0, 3, 4, 5, 1};
    int value = 5;
    void *ptr = &value;

    array_fill(arr, sizeof(int), 8, ptr, 3, 7);
    
    for(int i = 0; i < 7; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
