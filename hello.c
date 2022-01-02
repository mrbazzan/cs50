
#include <stdio.h>  // pre-processor directives

// MAKE A DICTIONARY?
// gcc -o hello hello.c -lcs50

// preprocessing: find and replace #include
// compiling: converts C syntax into an assembly language flavor
// assembling: assembly language is turned into machine code(0s and 1s)
// linking: stiches the different component into one ( hello.exe** )

void meow(int n);  // Prototyping

int main(void)
{
    char name;

    printf("What's your name? ");
    scanf("%s", &name);
    printf("hello, %s!\n", &name);

//    meow(3);
}


// the first 'void' means it does not return any output;
// the second 'void' means it does not take any input; it has been changed to int n
void meow(int n){
    do{
        printf("Enter a new value for n? ");
        scanf("%i", &n);
    }
    while (n < 1);  // It continues to run the "do" loop until while is false

    printf("%i", n);

    for (int i=0; i<n; i++){
        printf("meow\n");
    }

}