
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){

    char* word;
    int sentence = 0, num_word = 1;
    signed long letter = 0;

    printf("Text: ");
    for(int i=0; i<=1000; i++){
        word[i] = getc(stdin);
        if(word[i] == '\n'){
            word[i] = '\0';
            break;
        }
        if ((word[i]>='A' && word[i]<='Z')||(word[i]>='a' && word[i]<='z')){
            letter += 1;
        }
        if(word[i]=='!' || word[i]=='.' || word[i]=='?'){
            sentence += 1;
        }
        if(word[i]==' '){
            num_word += 1;
        }
    }

    double index = (0.0588* (letter*100)/num_word) - (0.296 * (sentence*100)/num_word) - 15.8;
    printf("Grade %d\n", (int) round(index));

    return 0;

}
