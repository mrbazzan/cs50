#include <stdio.h>

int parse_digit(char x){
    do{
        return x - '0';
    }while(x <= '9' && x >= '0');
}

int parse_mult(char **x){
    int total = parse_digit(*(*x));
    while(*(++*x) == '*'){
        total *= parse_digit(*(++*x));
    }
    return total;
}

int parse(char *x){
    int total = parse_mult(&x);
    while(*x++ == '+'){
        total += parse_mult(&x);
    }
    return total;
}

int main(void){
    char *x = "2*3+4*5";
    printf("%d\n", parse(x));
}