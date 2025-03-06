/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht search
*/

#include <stdlib.h>
#include "secured.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed_key;
    int index;
    bucket_t *bucket;

    if (ht == NULL || key == NULL)
        return NULL;
    hashed_key = ht->hash_func(key, ht->len);
    index = hashed_key % ht->len;
    bucket = ht->table[index];
    while (bucket != NULL) {
        if (bucket->key == hashed_key)
            return bucket->value;
        bucket = bucket->next;
    }
    return NULL;
}
