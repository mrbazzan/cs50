
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Converts void array into "pointer to char"; what we really want is the memory address
#define ELEMENT_AT(arr, i, size) (arr+((i)*size))

typedef char * str;


int int_compare_fn(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int str_compare_fn(const void *a, const void *b){
    return strcmp( *(str*)a, *(str*)b );
}


void bsort(void *arr, int len, size_t size, int (*compare_fn) (const void *, const void *)){
    void *temp = malloc(size);

    for(int i=0; i<len; i++){
        for(int j=0; j<len-1; j++){
            if(compare_fn(ELEMENT_AT(arr, j, size), ELEMENT_AT(arr, j+1, size)) > 0)  // (*compare_fn)(a, b)
            {
                memcpy(temp, ELEMENT_AT(arr, j, size), size);
                memcpy(ELEMENT_AT(arr, j, size), ELEMENT_AT(arr, j+1, size), size);
                memcpy(ELEMENT_AT(arr, j+1, size), temp, size);
            }
        }
    }
    free(temp);
}


int main(void){
    int int_arr[] = {4, 3, -2, 9, 9, 2, 10};
    bsort(int_arr, 7, sizeof(int), int_compare_fn);

    str str_arr[] = {"guava", "grape", "apple", "kiwi", "fruit", "melon", "grave"};
    bsort(str_arr, 7, sizeof(str), str_compare_fn);

    for(int i=0; i<7; i++){
        printf("%d ", *(int_arr+i));
    }
    printf("\n");
    for(int i=0; i<7; i++){
        printf("%s ", str_arr[i]);
    }
    printf("\n");
}
