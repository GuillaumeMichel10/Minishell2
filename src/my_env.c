/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_env
*/

#include "../mysh.h"

void my_env(mysh_t *mysh, node_t *node)
{
    node_t *env = mysh->env.first;

    while (env) {
        printf("%s\n", env->text[0]);
        env = env->next;
    }
}
