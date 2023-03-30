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

void loop(mysh_t *mysh)
{
    size_t n = 0;
    char *lineptr = NULL;

    while (1) {
        if (isatty(0))
            display_prompt();
        if (getline(&lineptr, &n, stdin) != -1) {
            run(mysh, lineptr);
            free (lineptr);
            lineptr = NULL;
        } else {
            return;
        }
    }
}
