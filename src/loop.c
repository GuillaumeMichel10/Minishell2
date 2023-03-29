/*
** EPITECH PROJECT, 2023
** src
** File description:
** loop
*/

#include "../mysh.h"

void display_prompt(void)
{
    my_putstr("$> ");
}

void loop(void)
{
    size_t n = 0;
    size_t nb_pipes = 0;
    char *lineptr = NULL;
    char ***commands = NULL;

    while (1) {
        if (isatty(0))
            display_prompt();
        if (getline(&lineptr, &n, stdin) != -1) {
            parse(lineptr, &commands, &nb_pipes);
            run(commands, nb_pipes);
            free (lineptr);
            lineptr = NULL;
        } else {
            return;
        }
    }
}
