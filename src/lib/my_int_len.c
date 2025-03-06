/*
** EPITECH PROJECT, 2025
** secured
** File description:
** my_int_len
*/

int my_intlen(int n)
{
    int len = 0;

    if (n == 0) {
        return 1;
    }
    while (n != 0) {
        n = n / 10;
        len++;
    }
    return len;
}
