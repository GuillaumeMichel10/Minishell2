/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include "../mysh.h"

void signal_handler(int signal)
{
    (void)signal;
}

int main(int ac, char **av, char **env)
{
    (void)av;
    int error = 0;
    signal(SIGINT, signal_handler);

    if (ac != 1)
        return (84);
    mysh_t mysh = setup(env);
    error = loop(&mysh);

    return (error);
}
