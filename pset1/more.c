
#include <stdio.h>

int get_height(void);

int main(void){

    int length;
    length = get_height();

    while (length < 1 || length > 8){
         length = get_height();
    }

    for (int i=1; i<length+1; i++){
        // Create the space in front of #
        for (int y=0; y<length-i; y++){
            printf(" ");
        }
        // Populate the #
        for (int j=0; j<i; j++){
            printf("#");
        }
        printf("  ");
        for (int j=0; j<i; j++){
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void){
    int i;
    // TODO: Take care of "letters or words" and "Enter key"
    printf("Height: ");
    scanf("%i", &i);
    return i;
}