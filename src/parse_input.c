/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

int check_file_permission(char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
        return (0);
    if (!S_ISREG(st.st_mode) || access(path, F_OK | X_OK) == -1)
        return (-1);
    return (1);
}

int valid_redirect(char **command)
{
    int redirect = 0;

    for (int i = 0; command[i]; ++i) {
        if (!my_strchr(command[i][0], "<>"))
            continue;
        if (i == 0) {
            my_puterr("Invalid null command.\n");
            return (0);
        }
        if (!command[i + 1] || my_strchr(command[i + 1][0], "<>")) {
            my_puterr("Missing name for redirect.\n");
            return (0);
        }
        if (++redirect > 1) {
            my_puterr("Ambiguous output redirect.\n");
            return (0);
        }
    }
    return (1);
}

int system_command(mysh_t *mysh, node_t *node)
{
    char *path = NULL;
    int permission = 0;

    for (int i = 0; mysh->path && mysh->path[i]; ++i) {
        path = my_concat(3, mysh->path[i], "/", node->text[0]);
        if ((permission += check_file_permission(path))) {
            node->str = path;
            return (1);
        }
    }
    return (permission);
}

int valid_command(mysh_t *mysh, node_t *node)
{
    int permission = 0;

    if (my_strchr('/', node->text[0])) {
        node->str = node->text[0];
        permission = check_file_permission(node->text[0]);
    } else {
        permission = system_command(mysh, node);
    }
    if (permission == 1)
        return (1);
    for (int i = 0; node->text[0][i]; ++i) {
        if (node->text[0][i] != '\\')
            my_putchar(node->text[0][i]);
    }
    if (permission == 0) {
        my_puterr(": Command not found.\n");
    } else {
        my_puterr(": Permission denied.\n");
    }
    return (0);
}

int valid_input(mysh_t *mysh, node_t *node)
{
    if (!valid_redirect(node->text))
        return (0);
    if (is_built_in(node->text[0]))
        return (1);
    if (!valid_command(mysh, node))
        return (0);
    return (1);
}
