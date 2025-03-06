/*
** EPITECH PROJECT, 2024
** test_sum_nbrs
** File description:
** test sum nbrs
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <secured.h>
#include <stdio.h>
#include <stdlib.h>

Test(new_hashtable, create_basic)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    cr_assert_not_null(ht);
}

Test(new_hashtable, create_huge)
{
    hashtable_t *ht = new_hashtable(&hash, 10000);

    cr_assert_not_null(ht);
}


Test(new_hashtable, create_no_indexs)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    cr_assert_null(ht);
}

Test(new_hashtable, null_function)
{
    hashtable_t *ht = new_hashtable(NULL, 10);

    cr_assert_null(ht);
}

Test(delete_hashtable, basic_deletion)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Chat", "Ouioui");
    ht_insert(ht, "Chien",  "Ouioui");
    ht_insert(ht, "Mdp",  "NonNon");
    ht_insert(ht, "Idk",  "Test");
    delete_hashtable(ht);
}

Test(delete_hashtable, NULL_deletion)
{
    hashtable_t *ht = new_hashtable(NULL, 10);

    delete_hashtable(ht);
}

Test(delete_hashtable, nothing_to_delete)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    delete_hashtable(ht);
}
