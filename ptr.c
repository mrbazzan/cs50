
#include <stdio.h>


struct person {
    int person_id;
    char *first_name;
    char *last_name;
};


int main(void){

//    struct person jacob = {1, "Jacob", "Dit"};
//
//    int age = 21;
//
//    int *age_pointer = &age;  // age_pointer is a pointer to integer; it is the memory address of where 21 is stored.
//
//    struct person *og = &jacob;
//
//    printf("%d\n", age_pointer);
//    age_pointer++;
//    printf("%d\n", age_pointer);
//    printf("Pointer: %d\n", *age_pointer); // de-referencing in the example;
//    printf("Address: %i\t sizeof: %ld\t sizeof pointer: %ld\n", &age, sizeof(age), sizeof(age_pointer));
//    printf("Pointer: %i\n", jacob.person_id);
//
//    printf("Pointer: %s\n", og->last_name);
//    printf("Pointer: %c\n", 'J');

    int num[3][4] = {
        {9, 10, 11, 12},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int *ptr = &num[0][0];
    int
        ROWS=3,
        COLS=4,
        TOTAL_CELLS=3*4,
        i;
    for(i=0; i<TOTAL_CELLS; i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");

    num[1][2];
    num[1][3];
}
