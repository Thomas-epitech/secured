/*
** EPITECH PROJECT, 2025
** secured
** File description:
** my strlen
*/

#include <stdio.h>

int my_strlen(const char *str)
{
    int counter = 0;

    if (str == NULL)
        return 0;
    for (; str[counter]; counter++);
    return counter;
}
