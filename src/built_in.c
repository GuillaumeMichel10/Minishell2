/*
** EPITECH PROJECT, 2023
** src
** File description:
** built_in
*/

#include "../mysh.h"

static const built_in_t call_fnct[] = {
    {"echo", &my_echo},
    {"cd", &my_cd},
    {"exit", &my_exit},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {NULL, NULL}
};

int is_built_in (char *str)
{
    for (int k = 1; call_fnct[k].ptr; k++) {
        if (my_strcmp(call_fnct[k].name, str) == 0){
            return (1);
        }
    }
    return (0);
}

int built_in(mysh_t *mysh, node_t *node)
{
    for (int k = 0; call_fnct[k].ptr; k++) {
        if (my_strcmp(call_fnct[k].name, node->text[0]) == 0){
            return (call_fnct[k].ptr(mysh, node));
        }
    }
    return (0);
}
