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
    /*Падает у тебя реалок, потому что ты портишь кучу*/
    /*Виновата переменная count, так как ты пытаешься усидеть на двух стульях*/
    /*используешь ее как индекс и как кол-во, и делаешь это не правильно*/
    int count = 0;
    size_t length;

    dynamic_massive = (char**)malloc(sizeof(char*)); /*почему count не увеличил*/
    if(dynamic_massive == NULL)/*отступ*/
    {
        printf("allocate fail!\n");
        free(dynamic_massive);
        return NULL;
    }
    fgets(main_string, MAX_MAIN_STRING, stdin);
    printf("Исходная строка: %s\n", main_string);
    while(*p_start != '\0') /*Нет проверки на \n*/ /*отступ*/
    {
        while(*p_end != ' ' && *p_end != '\n') /*Нет проверки на \0*/
        {
            p_end++;
        } 
        length = p_end - p_start;/*отступ*/
        if(length % 2 == 0 && length < 7)/*отступ*/
        {
            printf("Нечётное, либо слишком маленькое слово!\n");
            p_end++;
            p_start = p_end; /*Зачем else сделай continue*/
        }
        else
        {
            p_right = p_end - (length / 2);
            p_left = p_start + (length / 2) - 1;
            for(int i = 0; i < (length / 2); i++)/*отступ*/
            {
                if(strncmp(p_right, p_left, 1) != 0)
                {
                    printf("слово не симметрично!\n");
                    break; /*почитай про оператор goto*/
                }
                else
                {
                    p_right++;
                    p_left--;
                    check++; /*лишняя пременная, если исп оператор goto*/
                }
            }
            if(check >= 3)/*отступ*/
            {
                dynamic_massive[count] = (char*)calloc(length, sizeof(char)); /*Кто будет резервировать сивол завершения строки?*/
                if(dynamic_massive[count] == NULL) /*отступ*/
                {
                    printf("allocate fail!\n");
                    free(dynamic_massive[count]); /*а остальные строки и массив указателей, кто освобождать будет?*/
                    return dynamic_massive; /*зачем вовзращать не удачный массив? Так как ты его не NULL, но частично освободил, ф-ия получит указатель на память, подумает что все ок и упадет*/
                }
                for(int i = 0; i <= length; i++)/*отступ*/
                {
                    dynamic_massive[count][i] = p_start[i]; /*Ну ты выдал, все операции с символами и бувами snprintf*.
                    /*Если решил так поскудно сдеать, то не вижу символа завершения строки*/
                }
                char **massive_realloc = (char**)realloc(dynamic_massive, (count + 1) * sizeof(char*)); //При вводе более 3-х симметричных слов на 4-ом слове на этой строке проиходит aborted. realloc(): invalid next size. /*отступ*/
                /*char **massive_realloc = (char**)realloc(dynamic_massive, (count + 2) * sizeof(char*)); и заработает*/
                if(massive_realloc != NULL)/*отступ*/
                {
                    dynamic_massive = massive_realloc;
                    printf("%s\n", dynamic_massive[count]);
                    count++;
                }
                else /*Зачем проверку на ошибку пихать в else?*/
                {
                    printf("realloc failed!\n");
                    free(dynamic_massive);
                    return dynamic_massive;
                }
/*Выглаядит намного приятнее так, чем как выше
                if(massive_realloc == NULL)
                {
                    printf("realloc failed!\n");
                    free(dynamic_massive);
                    return dynamic_massive;
                }

                dynamic_massive = massive_realloc;
                printf("%s\n", dynamic_massive[count]);
                count++;
*/
            }

            p_end++;
            p_start = p_end;
        }
        length = 0;
        check = 0;
    }
    printf("Количество смметричных слов: %d\n", count);
    main_massive = dynamic_massive; /*Если вернуть dynamic_massive ничего не изменится, не понятно действие*/

    return main_massive;
}

int main()
{
    char **main_massive;

    func_dynamic_massive(main_massive);
    /*А память кто освобожать будет?*/
    return 0;
}
//abcdcba abcdcba abcdcba abcdcba
//abcdcba qwertytrewq ghjklkjhg
