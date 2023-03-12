#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUMBER 10

int main() {

    char str[NUMBER] = {0};
    
    char * check = fgets(str, NUMBER, stdin);
    int i = strlen(str);
    char * p = str[i];

    if (check == NULL){
        printf("ERROR");
        exit(1);
    }

    while(*p != 0) {
        printf("%c", *p);
        *p--;
    }

    return 0;
}
