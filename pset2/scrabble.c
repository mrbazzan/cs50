#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);

int main(void)
{
    char word1[15];
    char word2[15];
    // Get input words from both players
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);

    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score2 > score1) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }
    printf("\n");
}

int compute_score(char* word)
{
    // TODO: Compute and return score for string
    int total=0;
    for(int i=0; i<strlen(word)-1; i++){
        if (islower(word[i])){
            total += POINTS[word[i]-97];
        } else if (isupper(word[i])) {
            total += POINTS[word[i]-65];
        }
    }
    return total;
}
