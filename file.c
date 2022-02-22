
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r");
    if (!file){
        perror(NULL);
        return 1;
    }
    printf("Successful\n");
}
