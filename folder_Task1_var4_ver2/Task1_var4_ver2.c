#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 15

int main()
{
    char main_str[MAX] = {0}, str[MAX] = {0}, str_max[MAX] = {0};
    int i = 0, count = 0, start= 0, length = MAX, end = 1;

    fgets(main_str, MAX, stdin);

    char * p = main_str;
    char symb = *p;
    int main_length = strlen(main_str);

    while(length > 1)
    {
        count = 0;
        while(p < main_str + main_length)
        {

            if(*p == symb)
            {
                str[i] = *p;
            }

            else
            {
                i = 0;

                if(strlen(str) == 1 && str[i] != 10)
                {
                    memset(str, 0, MAX);
                    str[i] = *p;
                }

                else
                {

                    if(strlen(str) > strlen(str_max))
                    {
                        strcpy(str_max, str);
                        end = count;
                    }

                    memset(str, 0, MAX);
                    str[i] = *p;
                }

            }

            if(*p != 10)
            {
                symb = *p;
            }

            *p++;
            i++;
            count++;
        }
        count = end;
        length = strlen(str_max);

        if(length < 2)
        {
            continue;
        }

        start = end - length + 1;

        char * istr;

        istr = strstr(main_str + start - 1, str_max);

        printf("%d,%d%c\n", start, length, *istr);

        if(length > 1)
        {
            strncpy(main_str + start - 1, memset(str_max, 0, MAX), length);
            p = main_str;
        }

    }

    for(p = main_str; p < main_str + main_length; p++)
    {

        if(*p != 0)
        {
            printf("%c", *p);
        }

    }
    return 0;
}