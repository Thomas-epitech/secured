/*
** EPITECH PROJECT, 2025
** secured
** File description:
** my_putstr
*/

#include <unistd.h>
#include "secured.h"

void my_putstr(const char *str)
{
    (void)!write(1, str, my_strlen(str));
}
