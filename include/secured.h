/*
** EPITECH PROJECT, 2025
** secured
** File description:
** secured
*/
#ifndef SECURED_T
// Macros
    #define SECURED_T
    #define MAX_INT_T 2147483647
    #define TOTAL_PRIME_T 10
    #define POW_DOUBLE_LEN_T 1E140
typedef struct bucket {
    int key;
    char *value;
    struct bucket *next;
} bucket_t;

typedef struct {
    int (*hash_func)(char *, int);
    int len;
    bucket_t **table;
} hashtable_t;

// hash function
int get_index(double, int);
int hash(char *, int);

// hashtable functions
hashtable_t *new_hashtable(int (*)(char *, int), int);
void delete_hashtable(hashtable_t *);
int ht_insert(hashtable_t *, char *, char *);
int ht_delete(hashtable_t *, char *);
char *ht_search(hashtable_t *, char *);
int ht_dump(hashtable_t *);

// lib functions
void my_putchar(char);
int my_strlen(const char *);
void my_putstr(const char *);
void my_puterr(const char *);
int my_intlen(int);
int my_compute_power_rec(int, int);
double my_compute_power_rec_double(double nb, int p);
void my_put_nbr(int);
int mini_printf(const char *, ...);
char *my_strdup(const char *);
#endif /* !SECURED_T */
