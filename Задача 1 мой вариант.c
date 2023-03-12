#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h> 
#define NUM 20 
 
int main() { 
 
    char str[NUM] = {0}, chislo[NUM] = {0}; 
    int b = 0, j = 0, n = 0, max = 0, length = 0, a = 0, i = 0; 
     
    fgets(str, NUM, stdin); 
    for(char * p = str; *p != 0; *p++){ 
        if(*p >= 48 && *p <= 57) { 
            chislo[b] = *p; 
            b++; 
            if(*p - 48 > max) { 
                max = *p - 48; 
            } 
        } 
        else { 
            if(b != 0){ 
            length = strlen(chislo); 
            for(char * u = chislo; *u != 0; *u++){ 
                a = a + (*u - 48) * pow(max + 1, length - 1); 
                length--; 
            } 
            
            printf("%d", a);
             
            a = 0; 
            max = 0; 
            for(i = 0; i != b; i++){ 
            strcpy(chislo + i, ""); 
            } 
            b = 0; 
            } 
            if(*p < 48 || *p > 57){ 
                printf("%c", *p); 
            } 
 
        } 
    } 
 
    return 0; 
}