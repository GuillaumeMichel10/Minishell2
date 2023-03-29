/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

void parse(char *input, char ****commands, size_t *n)
{
    size_t k = 0;
    char **text = my_str_to_word_array(input, "|", n);

    if (commands[0])
        my_puterr("Free commands in parce.c\n");
    commands[0] = malloc(sizeof(char**) * (*n + 1));
    commands[0][*n] = NULL;
    for (int i = 0; text[i]; ++i)
        commands[0][i] = my_str_to_word_array(text[i], " \t\n", &k);
    --(*n);
}
