/*
** EPITECH PROJECT, 2025
** secured
** File description:
** delete hashtable
*/
#include <stdlib.h>
#include "secured.h"

static void delete_bucket(bucket_t *bucket)
{
    if (bucket == NULL)
        return;
    if (bucket->next != NULL)
        delete_bucket(bucket->next);
    free(bucket->value);
    free(bucket);
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++)
        delete_bucket(ht->table[i]);
    free(ht->table);
    free(ht);
}
