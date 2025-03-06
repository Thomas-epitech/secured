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

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ht_insert, basic, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    int ret = ht_insert(ht, "qijdiqzdqizdiqjodq",  "Ouioui");
    cr_assert_eq(ret, 0);
}

Test(ht_insert, null_ht, .init = redirect_all_std)
{
    hashtable_t *ht = NULL;

    int ret = ht_insert(ht, "qijdiqzdqizdiqjodq",  "Ouioui");
    cr_assert_eq(ret, 84);
}

Test(ht_insert, null_hash_func, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(NULL, 10);

    int ret = ht_insert(ht, "qijdiqzdqizdiqjodq",  "Ouioui");
    cr_assert_eq(ret, 84);
}

Test(ht_insert, null_key, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    int ret = ht_insert(ht, NULL,  "Ouioui");
    cr_assert_eq(ret, 84);
}

Test(ht_insert, null_value, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    int ret = ht_insert(ht, "Cause it won't crash",  NULL);
    cr_assert_eq(ret, 84);
}

Test(ht_search, basic_searching, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    int ret = ht_insert(ht, "Cause it won't crash",  "Caillou");
    my_putstr(ht_search(ht, "Cause it won't crash"));
    cr_assert_stdout_eq_str("Caillou");
    cr_assert_eq(ret, 0);
}

Test(ht_search, searching_null_ht, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Cause it won't crash", "idk");
    char *str = ht_search(NULL, "Cause it won't crash");
    cr_assert_null(str);
}

Test(ht_search, searching_null_value, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Cause it won't crash", "dz");
    char *str = ht_search(ht, NULL);
    cr_assert_null(str);
}

Test(ht_delete, delete_basic, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Cause it won't crash", "dz");
    int ret = ht_delete(ht, "Cause it won't crash");
    cr_assert_eq(ret, 0);
}

Test(ht_delete, delete_basic_unfound, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Cause it won't crash", "dz");
    int ret = ht_delete(ht, "It won't crash");
    cr_assert_eq(ret, 84);
}

Test(ht_delete, delete_null_ht, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(NULL, 10);

    ht_insert(ht, "Cause it won't crash", "dz");
    int ret = ht_delete(ht, "Cause it won't crash");
    cr_assert_eq(ret, 84);
}

Test(ht_delete, delete_null_value, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Cause it won't crash", "dz");
    int ret = ht_delete(ht, NULL);
    cr_assert_eq(ret, 84);
}

Test(ht_dump, dump_basic, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "Cause it won't crash", "dz");
    int ret = ht_dump(ht);
    cr_assert_eq(ret, 0);
}

Test(ht_dump, dump_empty, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    int ret = ht_dump(ht);
    cr_assert_eq(ret, 0);
}

Test(ht_dump, dump_null_hash, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(NULL, 10);

    int ret = ht_dump(ht);
    cr_assert_eq(ret, 84);
}
