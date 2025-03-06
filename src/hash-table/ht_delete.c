/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht delete
*/

#include <stdlib.h>
#include "secured.h"

static int delete_collided_key(bucket_t *bucket, int hashed_key)
{
    bucket_t *tmp;

    while (bucket->next != NULL) {
        if (bucket->next->key == hashed_key) {
            tmp = bucket->next->next;
            free(bucket->next);
            bucket->next = tmp;
            return 0;
        }
        bucket = bucket->next;
    }
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed_key;
    int index;
    bucket_t *bucket;
    bucket_t *tmp;

    if (ht == NULL || key == NULL)
        return 84;
    hashed_key = ht->hash_func(key, ht->len);
    index = hashed_key % ht->len;
    bucket = ht->table[index];
    if (bucket == NULL)
        return 84;
    if (bucket->key == hashed_key) {
        tmp = bucket->next;
        free(bucket);
        ht->table[index] = tmp;
        return 0;
    }
    return delete_collided_key(bucket, hashed_key);
}
