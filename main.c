/*
** EPITECH PROJECT, 2025
** secured
** File description:
** temporary main
*/

#include "secured.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 1);
//    char *test = strdup("bonjour");
    ht_insert(ht, "key", "bonjour");
//    free(test);
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
