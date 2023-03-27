#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

int max_string (char * main_str){
    char str[MAX] = {0}, str_max[MAX] = {0};
    int i = 0, count = 0, start = 0, max = 0, length = MAX, pos= 0, j = 1;

    
    char * p = main_str;
    char symb = 0, symb1 = *p;
    int main_length = strlen(main_str);
while(length > 1){
    count = 0;
    while(p < main_str + main_length)
    {

        if (*p == symb1){
        str[i] = *p;
        
        }
        else
        {
            i = 0;
            if(strlen(str) == 1 && str[i] != 10){
                memset(str, 0, MAX);
                str[i] = *p;
                symb = *p;
                max = 0;
            }
            else {
            max = (strlen(str) > strlen(str_max)); 
            if (max == 1)
            {
                strcpy(str_max, str);
                j = count;
            }
            memset(str, 0, MAX);
            str[i] = *p;
            symb = *p;
            max = 0;
            }
        }

        if(*p != 10)
        {
            symb1 = *p;
        }
        *p++;
        i++;
        count++;
    }
    count = j;
    length = strlen(str_max);
    if(length < 2){
        continue;
    }
    pos = j - length + 1;
    char * istr;
    istr = strstr(main_str + pos - 1, str_max);
    printf("%d,%d%c\n", pos, length, *istr);
    if(length > 1){  
    strncpy(main_str + pos - 1, memset (str_max, 0, MAX), length);
    p = main_str;
    }
}
for(p = main_str; p < main_str + main_length; p++){
    if (*p != 0){
        printf("%c", *p);
    }
}
return length;
}

int main()
{
    
    char main_str[MAX] = {0};
    
    fgets(main_str, MAX, stdin);
    max_string(main_str);

    return 0;
}