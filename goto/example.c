
#include <stdio.h>
#include <string.h>


struct cache_entry {
    int age;
    int number;
};


int main(void){

    struct cache_entry ce = {1, 2};
    struct cache_entry ced = {3, 5};

    struct cache_entry **active;

//    *active[1] = ced;

    printf("%d\n", ce.number);
}
