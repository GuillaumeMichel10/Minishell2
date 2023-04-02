/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

list_t *semicolons(mysh_t *mysh, char *input)
{
    size_t k = 0;
    list_t *list = new_liked_list();
    node_t *node = NULL;
    char **command = NULL;
    char **text = my_str_to_word_array(input, "|", &k);

    for (int i = 0; text[i]; ++i) {
        command = my_str_to_word_array(text[i], " \t\n", &k);
        if (!command || !command[0])
            continue;
        node = list->new(command, k);
        if (valid_input(mysh, node)) {
            list->add(list, node);
        } else {
            mysh->error = 1;
        }
    }
    return (list);
}

void parse(mysh_t *mysh, char *input)
{
    size_t k = 0;
    list_t *list = NULL;
    char **commands = my_str_to_word_array(input, ";", &k);

    mysh->commands = new_heap(k);
    for (int i = 0; commands[i]; ++i) {
        list = semicolons(mysh, commands[i]);
        mysh->commands.add(&mysh->commands, list);
    }
}
