
#include <stdio.h>


static int foo(int x){  // "static" is used to ensure that this function
    printf("%d\n", x);  // can only be used in this current file.
    return x+5;
}


int main(void){
    // name of function == address of the function
    int (*bar) (int x) = foo;

    int z = bar(3);
    printf("%d\n", z);
}
