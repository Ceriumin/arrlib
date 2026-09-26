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
        if(callback(bytes + idx * element_size)){
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

void *array_filter(void *arr, const size_t element_size, const size_t length, int callback(void * element)){
    unsigned char * bytes = (unsigned char*) arr;
    unsigned char * new_bytes = malloc(element_size * length);
    int curr_length = 0;

    for(size_t idx = 0; idx < length; idx++){
        if(callback(bytes + idx * element_size)){
            memcpy(new_bytes + curr_length * element_size, bytes + idx * element_size, element_size);
            curr_length++;
        }
    }

    return realloc(new_bytes, element_size * (length - curr_length));
}

void *array_find(void *arr, size_t element_size, size_t length, int callback(void * element)){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = 0; idx < length; idx++){
        if(callback(bytes + idx * element_size))
            return bytes + idx * element_size;
    }

    return NULL;
}

int array_find_index(void *arr, size_t element_size, size_t length, int callback(void * element)){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = 0 ; idx < length; idx++){
       if(callback(bytes + idx * element_size))
           return idx;
    }

    return -1;
}


void *array_find_last(void *arr, size_t element_size, size_t length, int callback(void *element)){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = length; idx >= 0; idx--){
        if(callback(bytes + idx * element_size))
            return bytes + idx * element_size;
    }

    return NULL;
}


int array_find_last_index(void *arr, size_t element_size, size_t length, int callback(void *element)){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = length; idx >= 0; idx--){
        if(callback(bytes + idx * element_size))
            return idx;
    }

    return -1;
}

// void * flat

// void * flatmap


void *array_foreach(void *arr, size_t element_size, size_t length, void callback(void *element)){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = 0; idx < length; idx++){
           callback(bytes + idx * element_size); 
    }

    return bytes;
}

int array_includes(void *arr, size_t element_size, size_t length, int callback(void *element)){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = 0; idx < length; idx++){
        if(callback(bytes + idx * element_size))
            return 1;
    }

    return 0;
}

int array_indexof(void *arr, size_t element_size, size_t length, void * element, int offset){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = offset; idx < length; idx++){
        if(bytes + idx * element_size == element)
            return idx;
    }

    return -1;
}

// join


//keys

int array_last_indexof(void *arr, size_t element_size, size_t length, void * element, int offset){
    unsigned char * bytes = (unsigned char *) arr;

    for(size_t idx = length - offset; idx >= 0; idx--){
        if(bytes + idx * element_size == element)
            return idx;
    }

    return -1;
}


void function(void * element){
    int *p = element;
    printf("%d\n", *p);
}

int main(void){
    int arr[8] = { 2, 5, 9, 0, 3, 4, 5, 1};
    
    array_foreach(arr, sizeof(int), 8, function);
    return 0;
}









