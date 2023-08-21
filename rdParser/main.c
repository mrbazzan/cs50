#include <stdio.h>
#include <stdlib.h>

/*
RECURSIVE DESCENT PARSER"
*/

typedef char * string;

int parseSum(string *word);
int parseFormula(string *word);

int parseNumber(string *word){
    int num = 0;
    do{
        // *(*pointer)++: dereference pointer, update the pointer then dereference
        num = (num*10) + **word-'0';
        (*word)++;
    }while(**word >= '0' && **word <= '9');

    // TODO: Add condition for '.'
    return num;
}

int parseFactor(string *word){
    if (**word >= '0' && **word <= '9'){
        return parseNumber(word);
    }
    else if(**word == '('){
        // move to the next token after the parenthesis
        (*word)++;
        int exp = parseSum(word);
        if (**word == ')')
        {
            (*word)++;
            return exp;
        }
    }
    else{
        printf("Only single digit are supported.\n");
    }
    printf("Error!\n");
    exit(24);
}

int parseProduct(string *word){
    int total = parseFactor(word);
    while(**word == '*'){
        ++*word;
        int num = parseFactor(word);
        total *= num;
    }
    return total;
}

int parseSum(string *word){
    int total = parseProduct(word);
    while(**word == '+'){
        ++*word;
        int num = parseProduct(word);
        total += num;
    }
    return total;
}

int parseFormula(string *word){
    int total = parseSum(word);
    if (**word == '\0'){
        return total;
    }
}

// [ ] subtraction
// [ ] division
// [ ] negation
// [ ] exponentiation

int main(void){
    string x = "2*(35+4)+2";
    printf("%d\n", parseFormula(&x));
    return 0;
}
