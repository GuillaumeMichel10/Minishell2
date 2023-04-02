/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_unsetenv
*/

#include "../mysh.h"


int my_unsetenv(mysh_t *mysh, node_t *command)
{
    node_t *node = mysh->list_env->first;

    if (command->len == 1) {
        my_puterr("unsetenv: Too few arguments.\n");
        mysh->error = 1;
        return (1);
    }
    for (int i = 1; node && command->text[i];) {
        if (my_strcmp(node->text[0], command->text[i]) == 0) {
            mysh->list_env->pop(mysh->list_env, node);
            my_update_env(mysh);
            node = mysh->list_env->first;
            ++i;
            continue;
        }
        if (!(node = node->next) && command->text[++i])
            node = mysh->list_env->first;
    }
    return (1);
}
