/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "../mysh.h"

void update_env(mysh_t *mysh)
{
    node_t *node = mysh->list_env.first;

    for (int i = 0; mysh->env; ++i)
        free(mysh->env[i]);
    free(mysh->env);

    mysh->env = malloc(sizeof(node_t) * (mysh->list_env.nb_nodes + 1));
    mysh->env[mysh->list_env.nb_nodes] = NULL;
    for (int i = 0; node; ++i) {
        mysh->env[i] = my_concat(3, node->text[0], "=", node->text[1]);
        node = node->next;
    }
}

list_t setup_env(char **env)
{
    list_t list = new_liked_list();
    char **text = 0;
    node_t *node = NULL;

    for (int i = 0; env[i]; ++i) {
        text = malloc(sizeof(char **) * 3);
        text[0] = my_strccpy(env[i], "=");
        text[1] = my_strcpy(env[i] + my_strlen(text[0]) + 1);
        text[2] = NULL;
        node = list.new(text, 2);
        list.add(&list, node);
    }

    return (list);
}

mysh_t setup(char **env)
{
    mysh_t mysh = {
        .commands = new_liked_list(),
        .list_env = setup_env(env),
    };
    update_env(&mysh);
    return (mysh);
}