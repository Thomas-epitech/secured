/*
** EPITECH PROJECT, 2025
** secured
** File description:
** hash
*/
#include <stdio.h>
#include "secured.h"

int const prime_list[TOTAL_PRIME_T] = {6199, 7121, 5659, 1993, 19009, 35527,
    14593, 569, 1487, 3089};

// Randoms operations:
// Modulos are used to limit the power of increasing
// a value (skill based matchmaking for each character)
double turn_str_into_double(char *str, int len)
{
    double to_ret = prime_list[len % TOTAL_PRIME_T];
    int i = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i++) {
        to_ret += str[i] * my_compute_power_rec_double(
        prime_list[str[i] % TOTAL_PRIME_T], (i % TOTAL_PRIME_T + 1) +
        str[i] % 5) + prime_list[(str[i] + 4) % TOTAL_PRIME_T];
        if (to_ret > POW_DOUBLE_LEN_T) {
            to_ret = prime_list[i % TOTAL_PRIME_T] + (str[i] >> 1) * to_ret /
            POW_DOUBLE_LEN_T;
        }
        to_ret *= ((len % 1000 + str[i]) * prime_list[(str[i] + 1) %
        TOTAL_PRIME_T]) / (i + 1);
    }
    if (i <= 1)
        to_ret *= to_ret;
    return to_ret;
}

// Get_index is used to randomize the hashed_value more,
// by getting the mid number of the previous squared hashed_value
int hash(char *str, int len)
{
    double hashed_value = turn_str_into_double(str, len);

    if (hashed_value == -1)
        return -1;
    hashed_value = get_index(hashed_value, MAX_INT_T);
    return hashed_value;
}
