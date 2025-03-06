/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht dump
*/

#include <stdio.h>
#include <stdlib.h>
#include "secured.h"

static void print_bucket(bucket_t *bucket)
{
    if (bucket == NULL)
        return;
    print_bucket(bucket->next);
    mini_printf("> %d - %s\n", bucket->key, bucket->value);
}

int ht_dump(hashtable_t *ht)
{
    if (ht == NULL)
        return 84;
    for (int i = 0; i < ht->len; i++) {
        mini_printf("[%d]:\n", i);
        print_bucket(ht->table[i]);
    }
    return 0;
}
