
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


struct node {
    char *word;
    struct node *next;
};


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

    // Initialize Linked-List
    struct node *head = NULL;
    struct node *tail = NULL;

    // Read file one line at a time
    char line[100];

    while(fgets(line, 100, file) != NULL){

        //Trim newline at the end of each word
        char *nl = strchr(line, '\n');
        if (nl) *nl = '\0';

        // CREATE NODE(1)
        struct node *n = malloc(sizeof(struct node));
        n->word = malloc(strlen(line) + 1);

        if (head == NULL){
            strcpy(n->word, line);
            head = n;
            tail = n;
        }else{
            strcpy(n->word, line);
            (*tail).next = n;
            tail = n;

        }
    }

    // Traverse the Linked List.
    struct node *current = head;
    while (current){
        printf("%s\n", current->word);
        current = current->next;
    }

}
