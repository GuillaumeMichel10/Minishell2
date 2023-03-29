/*
** EPITECH PROJECT, 2023
** src
** File description:
** execute
*/

#include "../mysh.h"

void execute(char **command, const int nb_pipes, const int n)
{
    static int pipe_fd[2][2];

    if (nb_pipes && pipe(pipe_fd[0]) == -1)
        return;
    if (fork() == 0 && connect_pipe(pipe_fd, nb_pipes, n) && redirect_out(command)) {
        execvp(command[0], command);
        exit(EXIT_FAILURE);
    }
    while (wait(NULL) >= 0);
    close_pipe(pipe_fd, nb_pipes, n);
    swap_pipe((int **)pipe_fd);
}

void run(char ***commands, const size_t nb_pipes)
{
    for (int i = 0; commands[i]; ++i){
        if (!commands[i][0])
            my_puterr("Invalid null command.\n");
        execute(commands[i], nb_pipes, i);
    }
}
