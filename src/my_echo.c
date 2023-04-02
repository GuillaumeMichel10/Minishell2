/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_echo
*/

#include "../mysh.h"

int expand_error_variable(mysh_t *mysh, node_t *node, int index)
{
    char *str = NULL;
    char *replace = NULL;
    int expanded = 0;

    if (my_strstr(node->text[index], "$?")) {
        replace = my_itoa(mysh->error);
        str = my_str_replace(node->text[index], replace, "$?");
        free(node->text[index]);
        node->text[index] = str;
        free(replace);
        expanded = 1;
    }

    return expanded;
}

int expand_environment_variables(mysh_t *mysh, node_t *node, int index)
{
    int expanded = 0;
    char *str = NULL;
    char *to_find = NULL;

    for (node_t *env = mysh->list_env->first; env; env = env->next) {
        to_find = my_concat(2, "$", env->text[0]);
        if (my_strstr(node->text[index], to_find)) {
            str = my_str_replace(node->text[index], env->text[1], to_find);
            free(node->text[index]);
            node->text[index] = str;
            free(to_find);
            expanded = 1;
            break;
        }
        free(to_find);
    }

    return expanded;
}

int expand_dollar(mysh_t *mysh, node_t *node, int index)
{
    int expanded = 0;

    if (expand_error_variable(mysh, node, index))
        expanded = 1;

    if (expand_environment_variables(mysh, node, index))
        expanded = 1;

    if (!expanded) {
        my_putstr(node->text[index]);
        my_putstr(": Undefined variable.\n");
        mysh->error = 1;
    }

    return expanded;
}

int my_echo(mysh_t *mysh, node_t *node)
{

    char *str = NULL;

    for (int i = 1; node->text[i]; ++i) {
        str = my_str_replace(node->text[i], "", "'");
        free(node->text[i]);
        node->text[i] = str;
        str = my_str_replace(node->text[i], "", "\"");
        free(node->text[i]);
        node->text[i] = str;
        if (my_strchr('$', node->text[i]) && !expand_dollar(mysh, node, i))
            return (1);
    }
    return (0);
}
