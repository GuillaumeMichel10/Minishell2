/*
** EPITECH PROJECT, 2023
** src
** File description:
** run
*/

#include "../mysh.h"

void run(mysh_t *mysh, char *lineptr)
{
    int status = 0;
    size_t nb_pipes = 0;
    node_t *node = NULL;

    parse(mysh, lineptr, &nb_pipes);
    node = mysh->commands.first;

    for (int i = 0; node; ++i) {
        if (!node->text[0])
            my_puterr("Invalid null command.\n");
        if (!built_in(mysh, node))
            execute(mysh, node, nb_pipes, i);
        node = node->next;
    }
    for (size_t i = 0; i < nb_pipes + 1; i++)
        wait(&status);
    mysh->commands = new_liked_list();
}
