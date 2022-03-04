
#include <stdio.h>

// COPIED FROM LINUX TORVALD'S INITIAL GIT COMMIT

static int verify_path(char *path)
{
    char c;

    goto inside;
    for (;;) {
        if (!c)
            return 1;
        if (c == '/') {
inside:
            c = *path++;
            if (c != '/' && c != '.' && c != '\0')
                continue;
            return 0;
        }
        c = *path++;
    }
}


int main(int argc, char **argv){
    int answer = verify_path(argv[1]);
    printf("%d\n", answer);
}