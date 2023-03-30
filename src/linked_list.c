/*
** EPITECH PROJECT, 2023
** src
** File description:
** redirect
*/

#include "../mysh.h"

static node_t *new (char **text, int len)
{
    node_t *node = malloc(sizeof(*node));

    if (!node) {
        my_puterr("can't malloc node in linked_list new()");
        return (NULL);
    }

    node->text = text;
    node->len = len;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}

static void add (list_t *list, node_t *node)
{
    if (!list || !node)
        return;

    if (list->nb_nodes == 0) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    ++list->nb_nodes;
}

list_t new_liked_list(void)
{
    list_t list = {
        .first = NULL,
        .last = NULL,
        .nb_nodes = 0,
        .add = add,
        .new = new
    };

    return (list);
}