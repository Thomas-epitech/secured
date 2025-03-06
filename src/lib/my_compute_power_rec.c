/*
** EPITECH PROJECT, 2024
** my_comput_power_rec
** File description:
** task04
*/


double my_compute_power_rec_double(double nb, int p)
{
    double nb_cp = nb;

    if (p < 0)
        return (1);
    if (p == 0)
        return (1);
    p--;
    for (int i = 0; i < p; i++) {
        nb *= nb_cp;
    }
    return (nb);
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}
