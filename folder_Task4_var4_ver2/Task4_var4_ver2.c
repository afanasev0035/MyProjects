#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_MAIN_STRING 100

char **func_dynamic_massive(char **main_massive)
{
    char main_string[MAX_MAIN_STRING] = {0};
    char **dynamic_massive = NULL;
    char *p_start = main_string;
    char *p_end = main_string;
    char *p_right = NULL;
    char *p_left = NULL;
    int check = 0;
    int count = 0;
    size_t length;

    dynamic_massive = (char**)malloc(sizeof(char*));
    if(dynamic_massive == NULL)
    {
        printf("allocate fail!\n");
        free(dynamic_massive);
        return NULL;
    }
    fgets(main_string, MAX_MAIN_STRING, stdin);
    printf("Исходная строка: %s\n", main_string);
    while(*p_start != '\0')
    {
        while(*p_end != ' ' && *p_end != '\n')
        {
            p_end++;
        }
        length = p_end - p_start;
        if(length % 2 == 0 && length < 7)
        {
            printf("Нечётное, либо слишком маленькое слово!\n");
            p_end++;
            p_start = p_end;
        }
        else
        {
            p_right = p_end - (length / 2);
            p_left = p_start + (length / 2) - 1;
            for(int i = 0; i < (length / 2); i++)
            {
                if(strncmp(p_right, p_left, 1) != 0)
                {
                    printf("слово не симметрично!\n");
                    break;
                }
                else
                {
                    p_right++;
                    p_left--;
                    check++;
                }
            }
            if(check >= 3)
            {
                dynamic_massive[count] = (char*)calloc(length, sizeof(char));
                if(dynamic_massive[count] == NULL)
                {
                    printf("allocate fail!\n");
                    free(dynamic_massive[count]);
                    return dynamic_massive;
                }
                for(int i = 0; i <= length; i++)
                {
                    dynamic_massive[count][i] = p_start[i];
                }
                char **massive_realloc = (char**)realloc(dynamic_massive, (count + 1) * sizeof(char*)); //При вводе более 3-х симметричных слов на 4-ом слове на этой строке проиходит aborted. realloc(): invalid next size.
                if(massive_realloc != NULL)
                {
                    dynamic_massive = massive_realloc;
                    printf("%s\n", dynamic_massive[count]);
                    count++;
                }
                else
                {
                    printf("realloc failed!\n");
                    free(dynamic_massive);
                    return dynamic_massive;
                }
            }
            p_end++;
            p_start = p_end;
        }
        length = 0;
        check = 0;
    }
    printf("Количество смметричных слов: %d\n", count);
    main_massive = dynamic_massive;

    return main_massive;
}

int main()
{
    char **main_massive;

    func_dynamic_massive(main_massive);

    return 0;
}
//abcdcba abcdcba abcdcba abcdcba
//abcdcba qwertytrewq ghjklkjhg