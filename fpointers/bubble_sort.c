
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char * str;


void bsort(void *arr, int len, int size){

    void *temp = malloc(size);

    for(int i=0; i<len; i++){
        for(int j=0; j<len-1; j++){
            if( strcmp( *((str*)arr+j), *((str*)arr+j+1) ) > 0 ){
                memcpy( temp, ((str*)arr+j), size );
                memcpy( ((str*)arr+j), ((str*)arr+j+1), size );
                memcpy( ((str*)arr+j+1), temp, size );
            }
        }
    }

    free(temp);
}


int main(void){
    str arr[] = {"guava", "grape", "apple", "kiwi", "fruit", "melon", "grave"};

    bsort(arr, 7, sizeof(str));

    for(int i=0; i<7; i++){
        printf("%s ", arr[i]);
    }
    printf("\n");
}
