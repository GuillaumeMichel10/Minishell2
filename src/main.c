/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include "../mysh.h"

int main(int ac, char **av, char **env)
{
    mysh_t mysh = setup(env);
    loop(&mysh);
}
