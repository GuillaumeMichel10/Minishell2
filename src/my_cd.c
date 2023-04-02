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

void my_chdir(mysh_t *mysh, char *path, char *cwd)
{
    if (chdir(path) == -1) {
        my_putstr(path);
        if (access(path, F_OK) == 0) {
            my_putstr(": Not a directory.\n");
        } else {
            my_puterr(": No such file or directory.\n");
        }
        mysh->error = 1;
        free (cwd);
        return;
    }
    free(mysh->oldpwd);
    mysh->oldpwd = cwd;
}

void my_cd_home(mysh_t *mysh, char *cwd)
{
    if (chdir(mysh->home) == -1) {
        my_puterr("cd: No home directory.");
        mysh->error = 1;
        free (cwd);
    }
}

void my_cd_with_args(mysh_t *mysh, node_t *node, char *cwd)
{
    if (my_strcmp(node->text[1], "-") == 0) {
        my_chdir(mysh, mysh->oldpwd, cwd);
    } else {
        my_chdir(mysh, node->text[1], cwd);
    }
}

int my_cd(mysh_t *mysh, node_t *node)
{
    char *cwd = get_current_working_directory();

    switch (node->len) {
        case 1 :
            my_cd_home(mysh, cwd);
            break;
        case 2 :
            my_cd_with_args(mysh, node, cwd);
            break;
        default:
            my_putstr("cd: Too many arguments.\n");
            mysh->error = 1;
            free(cwd);
    }

    return (1);
}
