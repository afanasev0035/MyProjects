#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUMBER 10

int main() {

    char str[NUMBER] = {0};

    if (NULL == (fgets(str, NUMBER, stdin))){
        printf("ERROR");
        exit(1);
    }

    for(int i = strlen(str); i >= 0; i--) {
        if (1 != (printf("%c", str[i]))){
            printf("ERROR");
            exit (1);
        }
    }

    return 0;
}

