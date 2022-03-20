
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Converts void array into int/str, and dereference it
#define INT(array, val) *((int*)array+val)
#define STR(array, val) ((str*)array+val)

typedef char * str;


void bsort(void *arr, int len, int size){

    void *temp = malloc(size);

    for(int i=0; i<len; i++){
        for(int j=0; j<len-1; j++){
            switch (size)
            {
                case 4:
                    if(INT(arr, j) > INT(arr, j+1))
                    {
                        int temp = INT(arr, j);
                        INT(arr, j) = INT(arr, j+1);
                        INT(arr, j+1) = temp;
                    }
                    break;
                case 8:
                    if( strcmp( *STR(arr, j), *STR(arr, j+1) ) > 0 )
                    {
                        memcpy( temp, STR(arr, j), size );
                        memcpy( STR(arr, j), STR(arr, j+1), size );
                        memcpy( STR(arr, j+1), temp, size );
                    }
                    break;
            }
        }
    }

    free(temp);
}


// TODO: Improve `bsort` to use cmp_fn

int main(void){
    int int_arr[] = {4, 3, -2, 9, 9, 2, 10};
    str str_arr[] = {"guava", "grape", "apple", "kiwi", "fruit", "melon", "grave"};

    bsort(int_arr, 7, sizeof(int));
    bsort(str_arr, 7, sizeof(str));

    for(int i=0; i<7; i++){
        printf("%d ", int_arr[i]);
        printf("%s ", str_arr[i]);
    }
    printf("\n");
}
