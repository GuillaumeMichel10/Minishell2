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
    char *lineptr = NULL;
    size_t n = 0;

    while (1) {
        if (isatty(0))
            display_prompt();
        if (getline(&lineptr, &n, stdin) != -1) {
            parse(lineptr);
            run();
            free (lineptr);
            lineptr = NULL;
        } else {
            return;
        }
    }
}
