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
    node->str = NULL;

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

void free_pop(node_t *node)
{
    for (int i = 0; node->text[i]; ++i)
        free(node->text[i]);
    free(node->text);
    free(node);
}

void pop(list_t *list, node_t *node)
{
    if (--list->nb_nodes == 0) {
        list->last = NULL;
        list->first = NULL;
        free_pop(node);
        return;
    }
    if (node == list->first) {
        list->first = node->next;
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        list->last->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free_pop(node);
}

list_t *new_liked_list(void)
{
    list_t *list = malloc(sizeof(*list));

    list->last = NULL;
    list->first = NULL;
    list->nb_nodes = 0;
    list->add = add;
    list->pop = pop;
    list->new = new;

    return (list);
}
