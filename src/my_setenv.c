/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_setenv
*/

#include "../mysh.h"

void my_setenv_with_args(mysh_t *mysh, node_t *command)
{
    char **env = NULL;
    node_t  *node = mysh->list_env->first;

    while (node) {
        if (my_strcmp(node->text[0], command->text[1]) == 0){
            free(node->text[1]);
            node->text[1] = my_strcpy(command->text[2]);
            my_update_env(mysh);
            return;
        }
        node = node->next;
    }
    env = malloc(sizeof(char *) * 3);
    env[2] = NULL;
    env[0] = my_strcpy(command->text[1]);
    env[1] = my_strcpy(command->text[2]);
    mysh->list_env->add(mysh->list_env, mysh->list_env->new(env, 2));
    my_update_env(mysh);
}

int validate_setenv_argument(mysh_t *mysh, const char *var_name)
{
    if (!my_isalpha(var_name[0]) && var_name[0] != '_') {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        mysh->error = 1;
        return 0;
    } else if (!my_str_isalpha(var_name)){
        my_putstr("setenv: Variable name must "
        "contain alphanumeric characters.\n");
        mysh->error = 1;
        return 0;
    } else {
        return 1;
    }
}

int my_setenv(mysh_t *mysh, node_t *node)
{
    for (int i = 0; node->text[i]; ++i)
        if (my_strchr(node->text[i][0], "<>"))
            return (0);
    switch (node->len) {
        case 1:
            return (0);
        case 2 ... 3:
            if (validate_setenv_argument(mysh, node->text[1])) {
                my_setenv_with_args(mysh, node);
            }
            break;
        default:
            my_putstr("setenv: Too many arguments.");
            mysh->error = 1;
            break;
    }
    return (1);
}
