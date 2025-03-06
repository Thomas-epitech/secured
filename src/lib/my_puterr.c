/*
** EPITECH PROJECT, 2025
** secured
** File description:
** my puterr
*/

#include <unistd.h>
#include "secured.h"

void my_puterr(const char *str)
{
    [[maybe_unused]] ssize_t tmp = write(2, str, my_strlen(str));
}
