/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

static const parsing_t parse_type[] = {
    {'|', &parse_pipe},
    {';', &parse_semicolon},
    {'<', &parse_redirect},
    {'>', &parse_redirect},
    {'\0', NULL}
};

bool check_type(lr_list_t *lr, char *data)
{
    for (int k = 0; parse_type[k].ptr; ++k) {
        if (data[0] == parse_type[k].c) {
            parse_type[k].ptr(lr, data);
            return (true);
        }
    }
    return (false);
}

void parse(char *input)
{
    char **text = my_str_to_word_array(input, " \t\n");

    lr_list_t lr = new_lr_list();

    for (int i = 0; text[i]; ++i) {
        if (check_type(&lr, text[i]))
            continue;
        if (lr.root && (lr.last->type == redirect || lr.last->type == arg)) {
            printf("1\n");
            lr.add_last(&lr, lr.new(arg, text[i]));
        } else {
            lr.add_last(&lr, lr.new(cmd, text[i]));
        }
    }
}
