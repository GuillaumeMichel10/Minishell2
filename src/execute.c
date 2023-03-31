/*
** EPITECH PROJECT, 2023
** src
** File description:
** execute
*/

#include "../mysh.h"

void execute(mysh_t *mysh, node_t *node, const int nb_pipes, const int n)
{
    static int pipe_fd[2][2];

    if (nb_pipes && pipe(pipe_fd[0]) == -1)
        return;
    pid_t pid = fork();
    if (pid == 0) {
        connect_pipe(pipe_fd, nb_pipes, n);
        redirect_out(node->text);
        redirect_in(node->text);
        if ((my_strcmp(node->text[0], "env") == 0)
        || (my_strcmp(node->text[0], "setenv")) == 0) {
            my_env(mysh);
        } else {
            execvp(node->text[0], node->text);
        }
        exit(EXIT_FAILURE);
    }
    close_pipe(pipe_fd, nb_pipes, n);
    swap_pipe((int **)pipe_fd);
}

