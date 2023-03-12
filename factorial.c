#include <stdio.h>

int factorial(int n)
{
    if (n == 0) 
        return 1;
    else
        return factorial(n - 1) * n;
}

int main() {

    int x = 0;
    scanf("%d", &x);
    printf("%d", factorial(x));

    return 0;
}