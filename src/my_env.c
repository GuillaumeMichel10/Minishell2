/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_env
*/

#include "../mysh.h"

void my_env(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i]; ++i) {
        my_putstr(mysh->env[i]);
        my_putchar('\n');
    }
}

int my_setenv(mysh_t *mysh, node_t *node)
{
    for (int i = 0; node->text[i]; ++i) {
        if (my_strchr(node->text[i][0], "<>"))
            return (0);
    }
    switch (node->len) {
        case 1:
            return (0);
        case 2 ... 3:

            return (1);
        default:
            my_putstr("setenv: Too many arguments.");
            return (1);
    }
}
