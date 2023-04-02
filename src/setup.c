/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "../mysh.h"

list_t *setup_env(char **env)
{
    list_t *list = new_liked_list();
    char **text = 0;
    node_t *node = NULL;

    for (int i = 0; env[i]; ++i) {
        text = malloc(sizeof(char **) * 3);
        text[0] = my_strccpy(env[i], "=");
        text[1] = my_strcpy(env[i] + my_strlen(text[0]) + 1);
        text[2] = NULL;
        node = list->new(text, 2);
        list->add(list, node);
    }

    return (list);
}

mysh_t setup(char **env)
{
    mysh_t mysh = {
        .list_env = setup_env(env),
        .exit = false
    };
    my_update_env(&mysh);
    return (mysh);
}
