
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int char_to_int(char word);
int digit_adder(int number);


int main(void){
    char number[20];

    printf("Enter Card Number: ");
    fgets(number, sizeof(number), stdin);

    int total = 0;
    for(int i=strlen(number)-2; i>=0; i-=2){
        if(i > 0 && i < strlen(number)-1){
            total += digit_adder(char_to_int(number[i-1])*2);
        }
        total += char_to_int(number[i]);
    }
    printf("The value of total is %d\n", total);

}


int char_to_int(char c){
    if (c >= '0' && c <= '9'){
        return c - 48;
    }
    exit(42);
}


int digit_adder(int number){

    int total = 0;
    char string[10];
    snprintf(string, 10, "%d", number);

    for(int i=0; i<strlen(string); i++){
        total += char_to_int(string[i]);
    }
    return total;
}

// TODO: I might have to write my default `len` function.
