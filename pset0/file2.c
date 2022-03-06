
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){

    if(argc < 2){
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(2);
    }

    // Load file into memory
    FILE *file = fopen(argv[1], "r");
    if (!file){
        perror(NULL);
        exit(1);
    }
    
    int capacity = 10;
    char **words = malloc(capacity * sizeof(char *));

    char line[100];
    int size = 0;
    while (fgets(line, 100, file) != NULL){  // `fgets` is used to read a file, one line at a time.

        //Trim newline at the end of each word
        char *nl = strchr(line, '\n');
        if (nl) *nl = '\0';

        char *word = malloc(strlen(line) + 1);
        strcpy(word, line); // Copy each line to the `word` memory.
        words[size] = word;
        size++;

        if(size == capacity){
            // Expand the array
            capacity += 10;
            words = realloc(words, capacity*sizeof(char *));
            
        }
    }
    
    for(int i=0; i<size; i++){
        printf("%d--->%s\n", i, words[i]);
    }

}
