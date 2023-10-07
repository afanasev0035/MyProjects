#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 31
#define MAX_INTERFACE 500

const int Table_size = 100;
int count = 0;
struct data 
{
    char surname[MAX], faculty[MAX], group[MAX];
    int id;
};

// Функция добавления элмента из main---------------------------------------------------------------------

int addPosition(struct data *table, char *surname_add, char *faculty_add, char *group_add, int id_add)
{
    if(count >= Table_size)
    {
        printf("Table is overloaded!");
        exit(1);
    }
    snprintf(table[count].surname, MAX, "%s", surname_add);
    snprintf(table[count].faculty, MAX, "%s", faculty_add);
    snprintf(table[count].group, MAX, "%s", group_add);
    table[count].id = id_add;
    count++;
}

// Функция добавления элмента при вводе с клавиатуры---------------------------------------------------------------------

int addPositionByKeyboard(struct data *table)
{
    int success = 0;
    getchar();
    if(count >= Table_size)
    {
        printf("Table is overloaded!");
        exit(1);
    }
    printf("Введите фамилию для добавления\n");
    for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &table[count].surname[i]);
            if(table[count].surname[i] == '\n')
            {
                table[count].surname[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            memset(table[count].surname, 0, MAX);
            return -1;
        }
    success = 0;
    printf("Введите факультет для добавления\n");
    for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &table[count].faculty[i]);
            if(table[count].faculty[i] == '\n')
            {
                table[count].faculty[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            memset(table[count].faculty, 0, MAX);
            return -1;
        }
    success = 0;
    printf("Введите группу для добавления\n");
    for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &table[count].group[i]);
            if(table[count].group[i] == '\n')
            {
                table[count].group[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            memset(table[count].group, 0, MAX);
            return -1;
        }
    success = 0;
    printf("Введите id для добавления\n");
    scanf("%d", &table[count].id);
    count++;
}

// Функция вывода таблицы----------------------------------------------------------------------

int showTable(struct data *table)
{
    printf("\nСписок студентов:\n");
    for(int i = 0; i <= count; i++)
    {
        printf("%s\t %s\t %s\t %d\n", table[i].surname, table[i].faculty, table[i].group, table[i].id);
    }
}

// Функция удаления позиции----------------------------------------------------------------------

int deletePosition(struct data *table)
{
    int position_number = 0;
    printf("Введите номер строки, которую требуется удалить\n");
    scanf("%d", &position_number);
    if(position_number > count)
    {
        printf("Такой строки в таблице нет!\n");
    }
    else 
    {
        for(int i = position_number; i <= count; i++)
        {
            table[i] = table[i + 1];
        }
        printf("Строка удалена!\n");
        memset(table[count].surname, 0, MAX);
        memset(table[count].faculty, 0, MAX);
        memset(table[count].group, 0, MAX);
        table[count].id = 0;
    }
    count--;
}

//Функция чтения строки посимвольно--------------------------------------------------------------------

int enterPosition(struct data *table, int stroka, int stolbec)
{
    int success = 0;
    getchar();
    if(stolbec == 0)
    {
        for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &table[stroka].surname[i]);
            if(table[stroka].surname[i] == '\n')
            {
                table[stroka].surname[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            return -1;
        }
    }
    if(stolbec == 1)
    {
        for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &table[stroka].faculty[i]);
            if(table[stroka].faculty[i] == '\n')
            {
                table[stroka].faculty[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            return -1;
        }
    }
    if(stolbec == 2)
    {
        for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &table[stroka].group[i]);
            if(table[stroka].group[i] == '\n')
            {
                table[stroka].group[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            return -1;
        }
    }
}

//Функция редактирования записи -------------------------------------------------------------------------

int editPosition(struct data *table)
{
    int stroka, stolbec;
    printf("Введите номер строки для изменения\n");
    scanf("%d", &stroka);
    printf("Введите номер столбца для изменения(0 - Фамилия, 1 - Факультет, 2 - Группа, 3 - Id)\n");
    scanf("%d", &stolbec);
    char surname_buf[MAX] = {0};
    char faculty_buf[MAX] = {0};
    char group_buf[MAX] = {0};
    snprintf(surname_buf, MAX, "%s", table[stroka].surname);
    snprintf(faculty_buf, MAX, "%s", table[stroka].faculty);
    snprintf(group_buf, MAX, "%s", table[stroka].group);
    int id_buf = table[stroka].id;
    printf("Введите новое значение\n");
    if(stolbec == 0)
    {
        memset(table[stroka].surname, 0, MAX);
        if(enterPosition(table, stroka, stolbec) == -1)
        {
            memset(table[stroka].surname, 0, MAX);
            snprintf(table[stroka].surname, MAX, "%s", surname_buf);
            return 1;
        }
    }
    if(stolbec == 1)
    {
        memset(table[stroka].faculty, 0, MAX);
        if(enterPosition(table, stroka, stolbec) == -1)
        {
            memset(table[stroka].faculty, 0, MAX);
            snprintf(table[stroka].faculty, MAX, "%s", faculty_buf);
            return 1;
        }
    }
    if(stolbec == 2)
    {
        memset(table[stroka].group, 0, MAX);
        if(enterPosition(table, stroka, stolbec) == -1)
        {
            memset(table[stroka].group, 0, MAX);
            snprintf(table[stroka].group, MAX, "%s", group_buf);
            return 1;
        }
    }
    if(stolbec == 3)
    {
        table[stroka].id = 0;
        scanf("%d", &table[stroka].id);
    }
}

//Функция поиска элемента -------------------------------------------------------------------------

int search(struct data *table)
{
    int stolbec, id1;
    int check = 0;
    int success = 0;
    char surname[MAX] = {0};
    char faculty[MAX] = {0};
    char group[MAX] = {0};
    printf("Введите номер столбца для поиска(0 - Фамилия, 1 - Факультет, 2 - Группа, 3 - Id)\n");
    scanf("%d", &stolbec);
    if(stolbec == 0)
    {
        printf("Введите искомую фамилию\n");
        getchar();
        for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &surname[i]);
            if(surname[i] == '\n')
            {
                surname[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            memset(surname, 0, MAX);
            return -1;
        }
        for(int i = 0; i <= count; i++)
        {
            if(strncmp(surname, table[i].surname, MAX) == 0)
            {
                printf("Искомая строка: %s %s %s %d\n", table[i].surname, table[i].faculty, table[i].group, table[i].id);
                check++; //break и return приведут к останову цикла или функции. В этом случае функция не найдёт другие строки с совпадающим значением, если такие есть
            }
            else if(i == count && check == 0)
            {
                printf("Строка не найдена\n");
                break;
            }
        }
    }
    if(stolbec == 1)
    {
        printf("Введите искомый факультет\n");
        getchar();
        for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &faculty[i]);
            if(faculty[i] == '\n')
            {
                faculty[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            memset(faculty, 0, MAX);
            return -1;
        }
        for(int i = 0; i <= count; i++)
        {
            if(strncmp(faculty, table[i].faculty, MAX) == 0)
            {
                printf("Искомая строка: %s %s %s %d\n", table[i].surname, table[i].faculty, table[i].group, table[i].id);
                check++; //break и return приведут к останову цикла или функции. В этом случае функция не найдёт другие строки с совпадающим значением, если такие есть
            }
            else if(i == count && check == 0)
            {
                printf("Строка не найдена\n");
                break;
            }
        }
    }
    if(stolbec == 2)
    {
        printf("Введите искомую группу\n");
        getchar();
        for(int i = 0; i < MAX; i++)
        {
            scanf("%c", &group[i]);
            if(group[i] == '\n')
            {
                group[i] = 0;
                success++;
                break;
            }
        }
        if(success == 0)
        {
            while (getchar() != '\n');
            printf("Превышено ограничение на ввод символов(30)!\n");
            memset(group, 0, MAX);
            return -1;
        }
        for(int i = 0; i <= count; i++)
        {
            if(strncmp(group, table[i].group, MAX) == 0)
            {
                printf("Искомая строка: %s %s %s %d\n", table[i].surname, table[i].faculty, table[i].group, table[i].id);
                check++; //break и return приведут к останову цикла или функции. В этом случае функция не найдёт другие строки с совпадающим значением, если такие есть
            }
            else if(i == count && check == 0)
            {
                printf("Строка не найдена\n");
                break;
            }
        }
    }
    if(stolbec == 3)
    {
        printf("Введите искомый id\n");
        scanf("%d", &id1);
        for(int i = 0; i <= count; i++)
        {
            if(id1 == table[i].id)
            {
                printf("Искомая строка: %s %s %s %d\n", table[i].surname, table[i].faculty, table[i].group, table[i].id);
                check++;
            }
            else if(i == count && check == 0)
            {
                printf("Строка не найдена\n");
                break;
            }
        }
    }
}

//Компараторы------------------------------------------------------------------------------------------------------

//Компаратор сортировки по Фамилии

int cmpSurname(const void *a, const void *b)
{
    return(strcmp(((const struct data *) a)->surname, ((const struct data *) b)->surname));
}

//Компаратор сортировки по Факультету

int cmpFaculty(const void *a, const void *b)
{
    return(strcmp(((const struct data *) a)->faculty, ((const struct data *) b)->faculty));
}

//Компаратор сортировки по Группе

int cmpGroup(const void *a, const void *b)
{
    return(strcmp(((const struct data *) a)->group, ((const struct data *) b)->group));
}

//Компаратор сортировки по id

int cmpId(const void *A, const void *B)
{
    int sortA;
    int sortB;
    if((sortA = ((const struct data *)A)->id) < (sortB = ((const struct data *)B)->id))
    {
        return -1;
    }
    else if(sortA == sortB)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Функция сортировки структуры------------------------------------------------------------------------------------

int sort(struct data *table)
{
    int stolbec;
    printf("Введите номер столбца для сортировки(0 - Фамилия, 1 - Факультет, 2 - Группа, 3 - Id)\n");
    scanf("%d", &stolbec);
    if(stolbec == 0)
    {
        qsort(table, count, sizeof(struct data), cmpSurname);
    }
    if(stolbec == 1)
    {
        qsort(table, count, sizeof(struct data), cmpFaculty);
    }
    if(stolbec == 2)
    {
        qsort(table, count, sizeof(struct data), cmpGroup);
    }
    if(stolbec == 3)
    {
        qsort(table, count, sizeof(struct data), cmpId);
    }
}

//Функция сортировки пузырьком--------------------------------------------------------------------

int sortBubble(struct data *table)
{
    int stolbec;
    char tmp[MAX];
    int tmpInt;
    printf("Введите номер столбца для сортировки(0 - Фамилия, 1 - Факультет, 2 - Группа, 3 - Id)\n");
    scanf("%d", &stolbec);
    printf("Сортировка по возрастанию - 0, по убыванию - 1\n");
    if(stolbec == 0)
    {
        for(int i = 0; i <= count; i++)
        {
            for(int j = 0; j < count - 1; j++)
            {
                if(strcmp(table[j].surname, table[j + 1].surname) > 0)
                {
                    strcpy(tmp, table[j].surname);
                    strcpy(table[j].surname, table[j + 1].surname);
                    strcpy(table[j + 1].surname, tmp);
                    strcpy(tmp, table[j].faculty);
                    strcpy(table[j].faculty, table[j + 1].faculty);
                    strcpy(table[j + 1].faculty, tmp);
                    strcpy(tmp, table[j].group);
                    strcpy(table[j].group, table[j + 1].group);
                    strcpy(table[j + 1].group, tmp);
                    tmpInt = table[j].id;
                    table[j].id = table[j + 1].id;
                    table[j + 1].id = tmpInt;
                }
            }
        }
    }
    if(stolbec == 1)
    {
        for(int i = 0; i <= count; i++)
        {
            for(int j = 0; j < count - 1; j++)
            {
                if(strcmp(table[j].faculty, table[j + 1].faculty) > 0)
                {
                    strcpy(tmp, table[j].surname);
                    strcpy(table[j].surname, table[j + 1].surname);
                    strcpy(table[j + 1].surname, tmp);
                    strcpy(tmp, table[j].faculty);
                    strcpy(table[j].faculty, table[j + 1].faculty);
                    strcpy(table[j + 1].faculty, tmp);
                    strcpy(tmp, table[j].group);
                    strcpy(table[j].group, table[j + 1].group);
                    strcpy(table[j + 1].group, tmp);
                    tmpInt = table[j].id;
                    table[j].id = table[j + 1].id;
                    table[j + 1].id = tmpInt;
                }
            }
        }
    }
    if(stolbec == 2)
    {
        for(int i = 0; i <= count; i++)
        {
            for(int j = 0; j < count - 1; j++)
            {
                if(strcmp(table[j].group, table[j + 1].group) > 0)
                {
                    strcpy(tmp, table[j].surname);
                    strcpy(table[j].surname, table[j + 1].surname);
                    strcpy(table[j + 1].surname, tmp);
                    strcpy(tmp, table[j].faculty);
                    strcpy(table[j].faculty, table[j + 1].faculty);
                    strcpy(table[j + 1].faculty, tmp);
                    strcpy(tmp, table[j].group);
                    strcpy(table[j].group, table[j + 1].group);
                    strcpy(table[j + 1].group, tmp);
                    tmpInt = table[j].id;
                    table[j].id = table[j + 1].id;
                    table[j + 1].id = tmpInt;
                }
            }
        }
    }
    if(stolbec == 3)
    {
        for(int i = 0; i <= count; i++)
        {
            for(int j = 0; j < count - 1; j++)
            {
                if(table[j].id > table[j + 1].id)
                {
                    strcpy(tmp, table[j].surname);
                    strcpy(table[j].surname, table[j + 1].surname);
                    strcpy(table[j + 1].surname, tmp);
                    strcpy(tmp, table[j].faculty);
                    strcpy(table[j].faculty, table[j + 1].faculty);
                    strcpy(table[j + 1].faculty, tmp);
                    strcpy(tmp, table[j].group);
                    strcpy(table[j].group, table[j + 1].group);
                    strcpy(table[j + 1].group, tmp);
                    tmpInt = table[j].id;
                    table[j].id = table[j + 1].id;
                    table[j + 1].id = tmpInt;
                }
            }
        }
    }
}

int main()
{
    char surname[MAX], faculty[MAX], group[MAX];
    char interface[MAX_INTERFACE] = {"Какое действие необходимо выполнить с таблицей?\n0 - добавление строки, 1 - вывод таблицы, 2 - удаление строки, 3 - редактирование позиции, 4 -найти позицию, 5 - отсортировать с помощью qsort, 6 - сортировка пузырьком, e - закончить работу с таблицей\n"};
    int id;
    int position_number = 0, stok;
    struct data table[Table_size];
    printf("Добавить 4 стоковых позиции в таблицу? 1 если да, 0 если нет\n");
    scanf("%d", &stok);
    if(stok == 1)
    {
    addPosition(table, "Cidorov", "Cecil", "CR", 777);
    addPosition(table, "Borisov", "Bro", "BR", 16);
    addPosition(table, "Abramov", "Aura", "CR", 16);
    addPosition(table, "Borisov", "Cecil", "AR", 200);
    }
    printf("%s\n", interface);
    while(1)
    {
        switch(getchar())
        {
            case '0': addPositionByKeyboard(table);
            printf("%s\n", interface);
            break;
            case '1': showTable(table);
            printf("%s\n", interface);
            break;
            case '2': deletePosition(table);
            printf("%s\n", interface);
            break;
            case '3': editPosition(table);
            printf("%s\n", interface);
            break;
            case '4': search(table);
            printf("%s\n", interface);
            break;
            case '5': sort(table);
            printf("%s\n", interface);
            break;
            case '6': sortBubble(table);
            printf("%s\n", interface);
            break;
            case 'e': return 0;
        }
    }
}