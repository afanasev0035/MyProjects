#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INP_SRT_LEN 20
#define MIN_ASCII 48
#define MAX_ASCII 57

int definition_of_number_order (int);
int changing_to_decimal_system (int, int *);

int definition_of_number_order (int number)
{
    int maximum_number = 0, current_number = 0;

    while(number > 0){
        current_number = number % 10;
        if(current_number > maximum_number){
            maximum_number = current_number;
        }
        number /= 10;
    }
    return ++maximum_number;
}

int changing_to_decimal_system (int number, int * position)
{
    int current_number = 0, converted_number = 0, maximum_number = 0;
    *position = 0;

    maximum_number = definition_of_number_order(number);

    while (number > 0)
    {
        current_number = number % 10;
        converted_number += current_number * pow(maximum_number, *position);
        number /= 10;
        *position += 1;
    }
    return converted_number;
}

int main()
{
    char input_string[INP_SRT_LEN] = {0};
    int number_string = 0, converted_number = 0, position_from_function = 0;
    fgets(input_string, INP_SRT_LEN, stdin);
    for(char * position = input_string; *position != 0; *position++){
        if(*position >= MIN_ASCII && *position <= MAX_ASCII) {
            number_string = atoi(position);
            converted_number = changing_to_decimal_system (number_string, &position_from_function);
            printf("%d", converted_number);
            position += position_from_function - 1;
        }
        else {
            printf("%c", *position);
        }
    }
    return 0;
}