
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int char_to_int(char word);
int digit_adder(int number);
long get_long(char* word);
int startswith(char* word, char* word_to_check);


int main(void){

    int total = 0;
    char number[17];
    char* card_type = "UNKNOWN";

    long value = get_long("Enter Card Number: ");
    snprintf(number, 17, "%li", value);

    if (strlen(number) < 13){
        printf("INVALID\n");
        return 0;
    }

    if (startswith(number, "51") || startswith(number, "52")
    || startswith(number, "53")  || startswith(number, "54") || startswith(number, "55")){
        card_type = "MASTERCARD";
    } else if (startswith(number, "34")
    || startswith(number, "37")){
        card_type = "AMEX";
    } else if (startswith(number, "4")){
        card_type = "VISA";
    }

    for(int i=strlen(number)-1; i>=0; i-=2){
        total += char_to_int(number[i]);
        if (i > 0){
            total += digit_adder(char_to_int(number[i-1]) * 2);
        }
    }

    if ((total % 10) == 0){
        printf("%s\n", card_type);
    } else {printf(" I don't know \n");}

}


int char_to_int(char c){
    if (c >= '0' && c <= '9'){
        return c - 48;
    }
    printf("Enter a number between 0 and 9\n");
    exit(42);

}


int digit_adder(int number){
    int total = 0;
    char string[10];
    snprintf(string, 10, "%d", number); // Converts number to a string

    for(int i=0; i<strlen(string); i++){
        total += char_to_int(string[i]);
    }
    return total;
}


long get_long(char* word){
    char number[17];
    do {
        printf("%s", word);
        scanf("%s", number);
    } while (strlen(number) > 16);

    for(int i=0; i<strlen(number); i++){
        char_to_int(number[i]);
    }

    return atol(number);
}


int startswith(char* word, char* word_to_check){
    for(int i=0; i<strlen(word_to_check); i++){
        if(word_to_check[i] != word[i]){
            return 0;
        }
    }
    return 1;
}