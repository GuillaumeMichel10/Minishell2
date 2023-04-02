/*
** EPITECH PROJECT, 2023
** src
** File description:
** redirect_in
*/

#include "../mysh.h"

void heredoc_loop(int *pipe_fd, const char *eof)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t size = 0;

    while (1) {
        my_putstr("? ");
        size = getline(&lineptr, &n, stdin);
        lineptr[size - 1] = '\0';
        if (my_strcmp(eof, lineptr) == 0) {
            free(lineptr);
            break;
        }
        write(pipe_fd[1], lineptr, size);
        write(pipe_fd[1], "\n", 1);
        free(lineptr);
        lineptr = NULL;
    }
}

static int handle_heredoc(const char *eof)
{
    int pipe_fd[2];
    pid_t pid = 0;

    if (pipe(pipe_fd) == -1)
        return (0);
    pid = fork();
    if (pid == 0) {
        close(pipe_fd[0]);
        heredoc_loop(pipe_fd, eof);
        close(pipe_fd[1]);
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
    }
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}

static void redirect_in_from(mysh_t *mysh, const char *filename, int option)
{
    static int input;
    if (input)
        close(input);
    if (option == 1) {
        input = open(filename, O_RDONLY, 0777);
    } else {
        input = handle_heredoc(filename);
    }
    if (input == -1) {
        my_putstr(filename);
        if (access(filename, F_OK) == -1) {
            my_puterr(": No such file or directory.\n");
        } else {
            my_puterr(": -: Is a directory");
        }
        mysh->error = 1;
        exit(0);
    }
    dup2(input, STDIN_FILENO);
    close(input);
}

int redirect_in(mysh_t *mysh, char **arguments)
{
    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], "<") == 0) {
            redirect_in_from(mysh, arguments[i + 1], 1);
            erase(&arguments[i], 2);
            return (0);
        }
        if (my_strcmp(arguments[i], "<<") == 0) {
            redirect_in_from(mysh, arguments[i + 1], 2);
            erase(&arguments[i], 2);
            return (0);
        }
    }
    return (true);
}
