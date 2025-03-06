/*
** EPITECH PROJECT, 2025
** secured
** File description:
** hash
*/
#include "secured.h"
#include <stdlib.h>

static int my_double_len(double n)
{
    int len = 0;

    if (n == 0)
        return 1;
    while (n > 1) {
        n /= 10.0;
        len++;
    }
    return len;
}

static int get_maximum_digits(int len, double seed)
{
    int to_ret = 0;

    if (len == 0)
        return 0;
    if (len == 1)
        return 1;
    len--;
    while (len > 0) {
        to_ret++;
        len /= 10;
    }
    while (my_double_len(seed * seed) / 2 < to_ret && to_ret > 1)
        to_ret--;
    return to_ret;
}

char *my_double_to_str(double n, int len)
{
    char *to_ret = malloc(sizeof(char) * (len + 1));
    int first_nb;

    for (int i = 0; i < len; i++) {
        first_nb = n / my_compute_power_rec_double(10, len - i - 1);
        to_ret[i] = first_nb + 48;
        n = n - first_nb * my_compute_power_rec_double(10, len - i - 1);
    }
    to_ret[len] = '\0';
    return to_ret;
}

int get_hash_value(double square_seed, int max_digits, int begin, int seed_len)
{
    int to_ret = 0;
    char *str_seed = my_double_to_str(square_seed, seed_len);

    for (int i = 0; i < max_digits; i++) {
        if (i >= my_double_len(square_seed))
            break;
        to_ret *= 10;
        to_ret += str_seed[begin + i] - 48;
    }
    free(str_seed);
    return to_ret;
}

int hash_seed(double seed, int max_digits)
{
    int seed_len;
    int begin;

    seed *= seed;
    seed_len = my_double_len(seed);
    begin = seed_len / 2;
    begin -= max_digits / 2;
    return get_hash_value(seed, max_digits, begin, seed_len);
}

int get_index(double seed, int len)
{
    int maximum_digits = get_maximum_digits(len, seed);

    seed = hash_seed(seed, maximum_digits);
    if (seed < 0)
        seed *= -1;
    return (int)seed % len;
}
