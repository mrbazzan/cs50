#include <stdio.h>

// Problem Statement
// In a population of n. Each year, n/3 people are born, and n/4 people pass away.
// How long will it take for the population to reach size, x.

int get_size(char* string, int point);
int get_int(char* string);

int main(void){

    int start = get_size("Start size: ", 9);
    int end = get_size("End size: ", start);

    int years = 0;
    while (end != start){
        start = start + (start/3) - (start/4);
        years++;

        if (start > end){ break; }
    }
    printf("Years: %d\n", years);

}


int get_int(char* string){
    int age;
    printf("%s", string);
    scanf("%d", &age);
    return age;
}

int get_size(char* string, int point){
    int integer = get_int(string);
    while(integer < point){
        integer = get_int(string);
    }
    return integer;
}
