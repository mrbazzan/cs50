
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float get_float(char* word);

int main(void){

    int total, count, cents;

    float dollar = get_float("Enter a number: ");
    cents = round(dollar*100);
    total = 0;
    count = 0;

    while (cents > 0){  // 25, 10, 5, 1
        if (cents >= 25){cents -= 25;}
        else if (cents >= 10){cents -= 10;}
        else if (cents >= 5){cents -= 5;}
        else if (cents >= 1){cents -= 1;}
        total += 1;
    }
    printf("%d\n", total);
}


float get_float(char* word){
    char number[10];
    do{
        printf("%s", word);
        fgets(number, sizeof(number), stdin);
    }while (atof(number) <= 0);

    return atof(number);
}
