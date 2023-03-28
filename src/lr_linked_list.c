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
    node->left = NULL;
    node->right = NULL;
    node->up = NULL;

    return (node);
}

void add(lr_list_t *list, lr_node_t *node)
{
    if (!list | !node)
        return;
    list->old = list->young;
    list->young = node;
    if (!list->old->left) {
        list->old->left = list->young;
        list->young->up = list->old;
    } else {
        list->old->right = list->young;
        list->young->up = list->old;
    }
}

void add_top(lr_list_t *list, lr_node_t *node)
{
    if (!list || !node)
        return;
    if (!list->top) {
        list->young = node;
        list->top = node;
    } else {
        list->old = list->young;
        list->young = node;
        list->top = node;
        list->top->left = list->old;
    }
}

lr_list_t new_lr_list(void)
{
    lr_list_t list = {
        .left = NULL,
        .top = NULL,
        .nb_nodes = 0,
        .new = new,
        .add = add,
        .add_top = add_top,
        .old = NULL,
        .young = NULL
    };

    return (list);
}


