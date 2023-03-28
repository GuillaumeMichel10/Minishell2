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

void parse_semicolon(lr_list_t *lr, char *data)
{
    lr->add_top(lr, lr->new(semicolon, data));
}

void parse_pipe(lr_list_t *lr, char *data)
{
    lr->add_top(lr, lr->new(pipeline, data));
}

void parse_redirect(lr_list_t *lr, char *data)
{
    lr->add_top(lr, lr->new(redirect, data));
}

void parse(char *input)
{
    char **text = my_str_to_word_array(input, " \t\n");

    lr_list_t lr = new_lr_list();

    for (int i = 0; text[i]; ++i) {
        for (int k = 0; parse_type[k].ptr; ++k) {
            if (text[i][0] == parse_type[k].c) {
                parse_type[k].ptr(&lr, text[i]);
                continue;
            }
        }
        if (!lr.top) {
            lr.add_top(&lr, lr.new(cmd, text[i]));
        } else {
            if (lr.old->type == redirect) {
                lr.add(&lr, lr.new(arg, text[i]));
            } else if (lr.old->type == arg) {
                lr.add(&lr, lr.new(arg, text[i]));
            } else {
                lr.add(&lr, lr.new(cmd, text[i]));
            }
        }
    }

    lr_node_t *node = lr.top;

    while (node){
        printf("%s\n", node->data);
        node = node->left;
    }
    lr.top = lr.new(cmd, text[0]);

}

