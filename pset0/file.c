
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){

    if(argc < 2){
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(2);
    }

    // Get the length of the file
    struct stat st;
    int return_value = stat(argv[1], &st);
    if (return_value == -1){
        fprintf(stderr, "Can't stat %s: ", argv[1]);
        perror(NULL);
        exit(1);
    }
    int size = st.st_size;

    // Load file into memory
    FILE *file = fopen(argv[1], "r");
    if (!file){
        perror(NULL);
        exit(1);
    }

    char *contents = malloc(size);
    fread(contents, size, 1, file); // Load all the files in memory at once
    fclose(file);

    // Get number of words in the file
    unsigned int num_words = 0;
    for(int i=0; i<size; i++){
        if (contents[i] == '\n') num_words++;

    }

    // Build an array of pointer to each word
    // char *words[num_words]; // Array of pointers to a char
    char **words = malloc(num_words * sizeof(char *));  // Array of pointers to a char in malloc

    // Loop through contents array:
    // ** Store where each word begins in words array
//     ** Replace newline with null char

    unsigned int word_count = 0;
    words[0] = &contents[0];
    // words[0] = contents; // This works too
    for(int i=0; i<size; i++){
        if (contents[i] == '\n'){
//            char *addr = &contents[i]; *addr = '\0';
            contents[i] = '\0';
            if (word_count < num_words){  // Take care of valgrind memory leak.
            // Basically, you don't want to access words after "the number of words in a.txt"
                words[word_count] = &contents[i+1];
                word_count++;
            }
        }
    }
}
