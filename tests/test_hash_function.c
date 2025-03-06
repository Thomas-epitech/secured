/*
** EPITECH PROJECT, 2025
** secured
** File description:
** test secured
*/
#include "secured.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(hash_function, basic)
{
    int ret = hash("Mot de passe de qualité.", 100);
    cr_assert_neq(ret, 0);
}

Test(hash_function, empty)
{
    int ret = hash("", 100);
    cr_assert_neq(ret, 0);
}

Test(hash_function, hash_null)
{
    int ret = hash(NULL, 100);
    cr_assert_eq(ret, -1);
}
