#include <stdio.h>
#include <stdlib.h>

/*
RECURSIVE DESCENT PARSER"
*/

typedef char * string;

int parseSum(string *word);


int parseFactor(string *word){
    if (**word >= '0' && **word <= '9'){
        return *(*word)++-'0';
    }
    else if(**word == '('){
        *(*word)++;
        int exp = parseSum(word);
        if (*(*word)++ == ')') return exp;
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

int main(void){
    string x = "2*(3+4)+2";
    printf("%d\n", parseSum(&x));
    return 0;
}