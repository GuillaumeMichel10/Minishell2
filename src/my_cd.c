/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_cd
*/

#include "../mysh.h"

char *get_current_working_directory(void)
{
    char *cwd;
    size_t size = 256;

    while (1) {
        cwd = malloc(sizeof(char) * size);
        if (getcwd(cwd, 256) != NULL)
            break;
        free(cwd);
        size *= 2;
    }
    return (cwd);
}

void run_chdir(mysh_t *mysh, char *path, char *cwd)
{
    if (chdir(path) == -1) {
        my_putstr(path);
        my_putstr(": Not a directory.\n");
        free (cwd);
        return;
    }
    free(mysh->oldpwd);
    mysh->oldpwd = cwd;
}

int my_cd(mysh_t *mysh, node_t *node)
{
    char *cwd = get_current_working_directory();

    switch (node->len) {
        case 1 :
            run_chdir(mysh, "/home", cwd);
            return (1);
        case 2 :
            if (my_strcmp(node->text[1], "-") == 0) {
                run_chdir(mysh, mysh->oldpwd, cwd);
                return (1);
            }
            run_chdir(mysh, node->text[1], cwd);
            return (1);
        default :
            my_putstr("cd: Too many arguments.\n");
            free (cwd);
            return (1);
    }
    return (0);
}
