/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_cd
*/

#include "../mysh.h"

//    while (mysh->list_env->first)
//        mysh->list_env->pop(mysh->list_env, mysh->list_env->last);
//    while (mysh->commands.size)
//        mysh->commands.pop(&mysh->commands);
//    free (mysh->commands.array);
//    for (int i = 0; mysh->env[i]; ++i)
//        free(mysh->env[i]);
//    free(mysh->env);
//    if (mysh->oldpwd)
//        free(mysh->oldpwd);
//    if (mysh->home)
//        free(mysh->home);

void exit_shell(mysh_t *mysh)
{
    mysh->exit = true;
}

void set_exit_status(mysh_t *mysh, const char *exit_arg)
{
    if (!my_str_isnum(exit_arg)) {
        if (my_isalpha(exit_arg[0])) {
            my_puterr("exit: Expression Syntax.\n");
        } else {
            my_puterr("exit: Badly formed number.\n");
        }
        mysh->error = 1;
    } else if (exit_arg[0] == '-' && !exit_arg[1]) {
        my_puterr("exit: Expression Syntax.\n");
        mysh->error = 1;
    } else {
        mysh->error = my_atoi(exit_arg) % 256;
        exit_shell(mysh);
    }
}

int my_exit(mysh_t *mysh, node_t *command)
{
    switch (command->len) {
        case 1:
            exit_shell(mysh);
            break;
        case 2:
            set_exit_status(mysh, command->text[1]);
            break;
        default:
            my_puterr("exit: Expression Syntax.\n");
            mysh->error = 1;
            break;
    }
    return (1);
}
