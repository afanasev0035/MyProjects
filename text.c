#include <stdio.h>  
#define NUM 10

void reverse(char *str)
{
	if (*str != 0 ) {
		reverse(str + 1);
		printf("%c", *str);
	}
}

int main() 
{  
    char str[NUM] = {0};
    fgets(str, NUM, stdin);
    reverse(str);

    return 0;
}