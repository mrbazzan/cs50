
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void key_checker(char* key);
char to_upper(char c);
char to_lower(char c);


int main(char argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    key_checker(argv[1]);

    char word[100], cipher;

    printf("plaintext: ");
    for(int i=0; i<=sizeof(word); i++){
        word[i] = getc(stdin);
        if(word[i] == '\n'){
            word[i] = '\0';
            break;
        }
    }

    printf("ciphertext: ");
    for(int i=0; i<strlen(word); i++){
        if (word[i] >= 'A' && word[i] <= 'Z'){
            cipher = to_upper(argv[1][(word[i] - 65) % 26]);
        } else if (word[i] >= 'a' && word[i] <= 'z'){
            cipher = to_lower(argv[1][(word[i] - 97) % 26]);
        } else {
            cipher = word[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
    return 0;
}


char to_upper(char c){
    if(isupper(c)){
        return c;
    }
    return c - 32;
}


char to_lower(char c){
    if (islower(c)){
        return c;
    }
    return c + 32;
}


bool check_if_in_array(char c, char* array){
    for(int i=0; i<strlen(array); i++){
        if(c == array[i]){
            return true;
        }
    }
    return false;
}


char check_if_an_alphabet(char c){
    if ((c>='A' && c<='Z')||(c>='a' && c<='z')){
        return c;
    }
    printf("Ensure key contains only alphabetic character\n");
    exit(42);
}


void key_checker(char* key){
    if (strlen(key) != 26){
        printf("Ensure key is equal to 26 characters\n");
        exit(42);
    }

    char alphabet[26];

    for(int i=0; i<strlen(key); i++){
        char c = check_if_an_alphabet(key[i]);
        if (check_if_in_array(c, alphabet)){
            printf("Ensure key contains each letter once\n");
            exit(42);
        }
        alphabet[i] = c;
    }
}
