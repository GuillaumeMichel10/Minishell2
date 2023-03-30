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

    while (1){
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
    if (!chdir(path)) {
        // cd_error(minishell);
        free (cwd);
        return;
    }
    free(mysh->oldpwd);
    mysh->oldpwd = cwd;
}

void my_cd(mysh_t *mysh, node_t *node)
{
    char *cwd = get_current_working_directory();

    switch (node->len) {
        case 1 :
            run_chdir(mysh, "/home", cwd);
            return;
        case 2 :
            if (my_strcmp(node->text[1], "-") == 0) {
                run_chdir(mysh, mysh->oldpwd, cwd);
                return;
            }
            run_chdir(mysh, node->text[1], cwd);
            return;
        default :
            my_putstr("cd: Too many arguments.\n");
            free (cwd);
            return;
    }
}
