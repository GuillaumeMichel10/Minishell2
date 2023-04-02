/*
** EPITECH PROJECT, 2023
** src
** File description:
** run
*/

#include "../mysh.h"

void handle_signal_error(int status)
{
    if (WIFSIGNALED(status)) {
        switch (WTERMSIG(status)) {
            case SIGSEGV:
                (WCOREDUMP(status)) ?
                my_puterr("Segmentation fault (core dumped)\n") :
                my_puterr("Segmentation fault\n");
                break;
            case SIGFPE:
                (WCOREDUMP(status))
                ? my_puterr("Floating exception (core dumped)\n")
                : my_puterr("Floating exception\n");
                break;
            case SIGABRT:
                my_puterr("Exec format error. Wrong Architecture.\n");
                break;
        }
    }
}

void run(mysh_t *mysh, list_t *commands)
{
    int status = 0;
    node_t *node = commands->first;

    if (commands->nb_nodes == 0)
        return;
    for (int i = 0; node; ++i) {
        if (!node->text[0])
            my_puterr("Invalid null command.\n");
        if (!built_in(mysh, node))
            execute(mysh, node, commands->nb_nodes - 1, i);
        if (node->next)
            mysh->error = 0;
        node = node->next;
    }
    for (int i = 0; i < commands->nb_nodes; i++) {
        wait(&status);
        handle_signal_error(status);
        if (mysh->error == 0 && WIFEXITED(status))
            mysh->error = WEXITSTATUS(status);
    }
}
