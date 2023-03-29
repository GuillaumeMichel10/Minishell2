/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse
*/

#include "../mysh.h"

void parse_semicolon(lr_list_t *lr, char *data)
{
    lr->add_first(lr, lr->new(semicolon, data));
}

void parse_pipe(lr_list_t *lr, char *data)
{
    lr->add_first(lr, lr->new(pipeline, data));
//    lr->first->output_fd = ;
    lr->first->input_fd = STDIN_FILENO;
}

void parse_redirect(lr_list_t *lr, char *data)
{
    lr->add_first(lr, lr->new(redirect, data));
    lr->first->output_fd = -1;
}