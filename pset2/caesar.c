
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int word_checker(char* word);


int main(char argc, char* argv[]){
    char word[100];
    char cipher;

    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    word_checker(argv[1]);

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
                cipher = 65 + (((word[i] - 65) + atoi(argv[1])) % 26);
        } else if (word[i] >= 'a' && word[i] <= 'z'){
            cipher = 97 + (((word[i] - 97) + atoi(argv[1])) % 26);
        } else {
            cipher = word[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
    return 0;

}


int word_checker(char* word){
    for(int i=0; i<strlen(word); i++){
        if (!(word[i] >= '0' && word[i] <= '9')){
            printf("Enter a non-negative integer.\n");
            exit(42);
        }
    }
}
