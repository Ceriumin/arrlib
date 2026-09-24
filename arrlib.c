#include <stdlib.h>
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

int function(void *element){
    return *((int *) element) > 10;
}

int main(void){
    int arr[5] = {3, 5, 1, 9, 4};
   
    printf("%d\n", array_every(arr, sizeof(int), 5, function));

    return 0;
}
