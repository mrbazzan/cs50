
#include <stdio.h>
#include "header.h"


int main(){
    for(int i=0; i<5; i++){
        someFunction();
        printf("The function \"someFunction()\" was called %d times\n", callCount);
    }

    return 0;
}
