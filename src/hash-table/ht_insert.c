/*
** EPITECH PROJECT, 2025
** secured
** File description:
** insert function
*/
#include <stdlib.h>
#include <stdio.h>
#include "secured.h"

static void fill_new_node(bucket_t *node, int key, char *value)
{
    node->key = key;
    node->value = my_strdup(value);
}

int insert_colliding_value(bucket_t *bucket, int hashed_key, char *value)
{
    while (bucket != NULL) {
        if (bucket->key == hashed_key) {
            fill_new_node(bucket, hashed_key, value);
            return 0;
        }
        if (bucket->next == NULL) {
            bucket->next = malloc(sizeof(bucket_t));
            fill_new_node(bucket->next, hashed_key, value);
            bucket->next->next = NULL;
            return 0;
        }
        bucket = bucket->next;
    }
    return 84;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed_key;
    int index;
    bucket_t *bucket;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    hashed_key = ht->hash_func(key, ht->len);
    index = hashed_key % ht->len;
    bucket = ht->table[index];
    if (bucket == NULL) {
        ht->table[index] = malloc(sizeof(bucket_t));
        fill_new_node(ht->table[index], hashed_key, value);
        ht->table[index]->next = NULL;
        return 0;
    }
    return insert_colliding_value(bucket, hashed_key, value);
}
