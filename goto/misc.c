
#include <stdio.h>


int main(void){

    int num, i = 1;
    printf("Enter the number: ");
    scanf("%d", &num);

table:
    printf("%d x %d = %d\n", num, i, num*i);
    i++;

    if (i<10)
    goto table;

    printf("-----------*****-------------");

    int i, j, k;
    for(i=0; i<10; i++){
        for(j=0; j<5; j++){
            for(k=0; k<3; k++){
                printf("%d %d %d\n", i, j, k);
                if (i==2){ goto out; }  // This is used to prematurely get out of the loop
            }
        }
    }

out:
    printf("Came out of the loop\n");
}
