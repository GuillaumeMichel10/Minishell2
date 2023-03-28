/*
** EPITECH PROJECT, 2023
** src
** File description:
** mysh
*/

#pragma once

#include "lib/my/libmy.h"

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

typedef enum type_s{
    cmd, // : pour représenter une commande (par exemple, ls, echo, mkdir, etc.)
    arg, // : pour représenter un argument de commande (par exemple, -l, -a, filename.txt, etc.)
    redirect, // : pour représenter une redirection d'entrée ou de sortie (par exemple, <, >, >>, etc.)
    pipeline, // : pour représenter un pipeline (par exemple, |)
    and, // : pour représenter l'opérateur logique &&
    or, // : pour représenter l'opérateur logique ||
    semicolon, // : pour représenter le point-virgule ;
    bg, // : pour représenter le caractère & utilisé pour lancer une commande en arrière-plan
    subshell, // : pour représenter une commande à exécuter dans un sous-shell
    not // : pour représenter l'opérateur logique !
}type_t;

typedef struct lr_node_s{
    type_t type;
    char *data;
    struct lr_node_s *left;
    struct lr_node_s *up;
    struct lr_node_s *right;
}lr_node_t;

typedef struct lr_list_s{
    int nb_nodes;
    lr_node_t *old;
    lr_node_t *young;
    lr_node_t *top;
    lr_node_t *left;
    struct lr_node_s *(*new)(type_t, char *);
    void (*add)(struct lr_list_s *, lr_node_t *);
    void (*add_top)(struct lr_list_s *, lr_node_t *);

}lr_list_t;

lr_list_t new_lr_list(void);

typedef struct parsing_s{
    char c;
    void (*ptr)(lr_list_t *, char *);
}parsing_t;

void parse(char *);
void parse_pipe(lr_list_t *, char *);
void parse_semicolon(lr_list_t *, char *);
void parse_redirect(lr_list_t *, char *);

void loop();
