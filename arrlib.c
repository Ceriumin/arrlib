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


int main(void){
    int arr[8] = { 2, 5, 9, 0, 3, 4, 5, 1};

    return 0;
}
