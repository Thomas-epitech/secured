/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** strdup
*/
#include <stdlib.h>
#include <secured.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *to_ret = malloc(sizeof(char) * my_strlen(src) + 1);

    my_strcpy(to_ret, src);
    return (to_ret);
}
