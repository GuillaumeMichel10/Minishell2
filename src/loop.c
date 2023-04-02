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

int loop(mysh_t *mysh)
{
    size_t n = 0;
    char *lineptr = NULL;

    while (1) {
        if (isatty(0))
            display_prompt();
        if (getline(&lineptr, &n, stdin) == -1)
            return (mysh->error);
        parse(mysh, lineptr);
        for (int i = 0; i < mysh->commands.size; ++i)
            run(mysh, mysh->commands.array[i]);
        free (lineptr);
        lineptr = NULL;
        if (mysh->exit)
            return (mysh->error);
    }
}
