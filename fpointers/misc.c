
#include <stdio.h>


int foo(int x){
    printf("%d\n", x);
    return x+5;
}


int main(void){
    // name of function == address of the function
    int (*bar) (int x) = foo;

    int z = bar(3);
    printf("%d\n", z);
}
