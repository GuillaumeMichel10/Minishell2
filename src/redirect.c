/*
** EPITECH PROJECT, 2023
** src
** File description:
** redirect
*/

#include "../mysh.h"


static void	redirect_out_to(const char *filename)
{
    static int output;

    if (output)
        close(output);
//    if (option == TRUNCATE)
        output = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
//    else
//        output = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
//    if (output == ERROR)
//        exit_error("open");
    dup2(output, STDOUT_FILENO);
    close(output);
}

int redirect_out(char **command)
{
    for (int i = 0; command[i]; ++i) {
        if (my_strcmp(command[i], ">") == 0) {
            redirect_out_to(my_strcpy(command[i + 1]));

        }
//        if (my_strcmp(command[i], ">>") == 0) {
//            redirect_out_to();
//        }
    }
    return (true);
}
