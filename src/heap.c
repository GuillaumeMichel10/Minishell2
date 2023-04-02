/*
** EPITECH PROJECT, 2023
** src
** File description:
** heap
*/

#include "../mysh.h"

static void pop(heap_t *heap)
{
    if (heap->size == 0)
        return;
    while ((heap->array[heap->size - 1]->first))
        heap->array[heap->size - 1]->pop(
            heap->array[heap->size - 1], heap->array[heap->size - 1]->last
        );
    --heap->size;
}

static void add(heap_t *heap, list_t *list)
{
    if (heap->size == heap->capacity) {
        my_puterr("heap to samll");
        return;
    }
    heap->array[heap->size++] = list;
}

heap_t new_heap(int capacity)
{
    heap_t heap = {
        .size = 0,
        .capacity = capacity,
        .array = malloc(sizeof(list_t *) * capacity),
        .add = add,
        .pop = pop
    };

    return (heap);
}
