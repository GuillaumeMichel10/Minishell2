/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_env
*/

#include "../mysh.h"

void my_reset_env(mysh_t *mysh)
{
    if (mysh->oldpwd) {
        free(mysh->oldpwd);
        mysh->oldpwd = NULL;
    }
    if (mysh->home) {
        free(mysh->home);
        mysh->home = NULL;
    }
    if (mysh->path) {
        for (int i = 0; mysh->path[i]; ++i)
            free(mysh->path[i]);
        free(mysh->path);
        mysh->path = NULL;
    }
    if (mysh->env) {
        for (int i = 0; mysh->env[i]; ++i)
            free(mysh->env[i]);
        free(mysh->env);
        mysh->env = NULL;
    }
}

void my_update_env(mysh_t *mysh)
{
    node_t *node = mysh->list_env->first;
    size_t k = 0;

    my_reset_env(mysh);

    mysh->env = malloc(sizeof(node_t) * (mysh->list_env->nb_nodes + 1));
    mysh->env[mysh->list_env->nb_nodes] = NULL;
    for (int i = 0; node; ++i) {
        if (my_strcmp(node->text[0], "HOME") == 0)
            mysh->home = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "OLDPWD") == 0)
            mysh->oldpwd = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "PATH") == 0)
            mysh->path = my_str_to_word_array(node->text[1], ":", &k);
        mysh->env[i] = my_concat(3, node->text[0], "=", node->text[1]);
        node = node->next;
    }
}

void my_env(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i]; ++i) {
        my_putstr(mysh->env[i]);
        my_putchar('\n');
    }
}
