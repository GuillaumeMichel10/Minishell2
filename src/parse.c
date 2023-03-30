/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

int valid_command(char **command)
{
    int redirect = 0;

    for (int i = 0; command[i]; ++i) {
        if (!my_strchr(command[i][0], "<>"))
            continue;
        if (i == 0) {
            my_puterr("Invalid null command.\n");
            return (0);
        }
        if (!command[i + 1] || my_strchr(command[i + 1][0], "<>")) {
            my_puterr("Missing name for redirect.\n");
            return (0);
        }
        if (++redirect > 2) {
            my_puterr("Ambiguous output redirect.\n");
            return (0);
        }
    }

    return (1);
}

void parse(mysh_t *mysh, char *input, size_t *n)
{
    size_t k = 0;
    node_t *node = NULL;
    char **command = NULL;
    char **text = my_str_to_word_array(input, "|", n);

    if (mysh->commands.nb_nodes != 0)
        my_puterr("free");
    for (int i = 0; text[i]; ++i) {
        command = my_str_to_word_array(text[i], " \t\n", &k);
        if (valid_command(command)) {
            node = mysh->commands.new(command, k);
            mysh->commands.add(&mysh->commands, node);
        } else {}
    }
    --(*n);
}
