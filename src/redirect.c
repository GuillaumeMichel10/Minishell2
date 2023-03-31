/*
** EPITECH PROJECT, 2023
** src
** File description:
** redirect
*/

#include "../mysh.h"

static void	redirect_out_to(const char *filename, int option)
{
    static int output;

    if (output)
        close(output);
    if (option == 1) {
        output = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    }
    if (option == 2) {
        output = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    }
//    if (output == ERROR)
//        exit_error("open");
    dup2(output, STDOUT_FILENO);
    close(output);
}

static void	redirect_in_from(const char *filename)
{
    static int input;

    if (input)
        close(input);
    input = open(filename, O_RDONLY, 0777);
//    if (input == ERROR)
//        exit_error("open");
    dup2(input, STDIN_FILENO);
    close(input);
}

void erase(char **text, size_t n)
{
    for (size_t j = 0; j < n; ++j) {
        for (int i = 0; text[i]; ++i) {
            text[i] = text[i + 1];
        }
    }
}

int redirect_in(char **arguments)
{
    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], "<") == 0 || my_strcmp(arguments[i], "<<") == 0) {
            redirect_in_from(arguments[i + 1]);
            erase(&arguments[i], 2);
            return (0);
        }
    }
    return (true);
}

int redirect_out(char **arguments)
{
    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], ">") == 0) {
            redirect_out_to(arguments[i + 1], 1);
            erase(&arguments[i], 2);
            return (0);
        }
        if (my_strcmp(arguments[i], ">>") == 0) {
            redirect_out_to(arguments[i + 1], 2);
            erase(&arguments[i], 2);
            return (0);
        }
    }
    return (true);
}
