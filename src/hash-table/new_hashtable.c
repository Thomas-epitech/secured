/*
** EPITECH PROJECT, 2025
** secured
** File description:
** new hashtable function
*/
#include <stdlib.h>
#include "secured.h"

hashtable_t *new_hashtable(int (*hash_func)(char *, int), int len)
{
    hashtable_t *hashtable;

    if (len <= 0 || hash_func == NULL)
        return NULL;
    hashtable = malloc(sizeof(hashtable_t));
    if (hashtable == NULL || hash_func == NULL)
        return NULL;
    hashtable->hash_func = hash_func;
    hashtable->len = len;
    hashtable->table = malloc(sizeof(bucket_t *) * len);
    if (hashtable->table == NULL) {
        free(hashtable);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        hashtable->table[i] = NULL;
    return hashtable;
}
