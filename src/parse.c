/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

void parse(char *input)
{
    char **text = my_str_to_word_array(input, " \t\n");

    for (int i = 0; text[i]; ++i) {
        printf("%s\n", text[i]);
    }
}

