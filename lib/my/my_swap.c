/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_swap
*/

/*swap 2 pointers, example :
    with 2 str : my_swap(&str1, &str2);
    with 2 int : my_swap(&nbr1, &nbr2);
*/
void my_swap(void **a, void **b)
{
    void *tmp = *a;

    *a = *b;
    *b = tmp;
}
