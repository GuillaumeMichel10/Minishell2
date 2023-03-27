/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_nbrlen
*/

int my_nbrlen(int nb)
{
    int i = 0;

    while (nb){
        nb /= 10;
        ++i;
    }
    return (i);
}
