/*
** EPITECH PROJECT, 2023
** src
** File description:
** lr_linked_list
*/

#include "../mysh.h"

lr_node_t *new(type_t type, char *data)
{
    lr_node_t *node = malloc(sizeof(*node));

    node->type = type;
    node->data = data;
    node->child = NULL;
    node->next = NULL;
    node->input_fd = -1;
    node->output_fd = -1;

    return (node);
}

void add_last(lr_list_t *list, lr_node_t *node)
{
    if (!list || !node)
        return;
    if (!list->root) {
        list->last = node;
        list->first = node;
        list->root = node;
    } else {
        list->last->child = node;
        list->last = node;
    }
}

void add_first(lr_list_t *list, lr_node_t *node)
{
    if (!list || !node)
        return;
    if (!list->root) {
        list->last = node;
        list->first = node;
        list->root = node;
    } else {
        list->first->next = node;
        list->first = node;
        list->last = node;
    }
}

lr_list_t new_lr_list(void)
{
    lr_list_t list = {
        .first = NULL,
        .last = NULL,
        .root = NULL,
        .new = new,
        .add_first = add_first,
        .add_last = add_last
    };

    return (list);
}


