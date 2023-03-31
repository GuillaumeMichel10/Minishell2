/*
** EPITECH PROJECT, 2023
** src
** File description:
** built_in
*/

#include "../mysh.h"

static const built_in_t call_fnct[] = {
    {"cd", &my_cd},
//    {"exit", &my_exit},
    {"setenv", &my_setenv},
//    {"unsetenv", &my_unsetenv},
//    {"echo", &my_echo},
    {NULL, NULL}
};

int built_in(mysh_t *mysh, node_t *node)
{
    for (int k = 0; call_fnct[k].ptr; k++) {
        if (my_strcmp(call_fnct[k].name, node->text[0]) == 0){
            return (call_fnct[k].ptr(mysh, node));
        }
    }
    return (0);
}
