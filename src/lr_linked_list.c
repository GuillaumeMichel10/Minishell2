/*
** EPITECH PROJECT, 2023
** src
** File description:
** lr_linked_list
*/

#include "lr_linked_list.h"

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

void add_left(lr_list_t *list, lr_node_t *parent, lr_node_t *child)
{
    if (parent->left)
        return;
    parent->left = child;
    child->up = parent;
    ++list->nb_nodes;
}

void add_right(lr_list_t *list, lr_node_t *parent, lr_node_t *child)
{
    if (parent->right)
        return;
    parent->right = child;
    child->up = parent;
    ++list->nb_nodes;
}

void add_up(lr_list_t *list, lr_node_t *child, lr_node_t *parent)
{
    if (child->up)
        return;
    child->up = parent;
    parent->left = child;
    ++list->nb_nodes;
    list->top = parent;
}

lr_list_t new_lr_list(void)
{
    lr_list_t list = {
        .left = NULL,
        .top = NULL,
        .nb_nodes = 0,
        .new = new,
        .add_left = add_left,
        .add_right = add_right,
        .add_up = add_up
    };

    return (list);
}


