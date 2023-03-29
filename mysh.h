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
#include <sys/types.h>
#include <sys/wait.h>

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

typedef struct lr_node_s {
    int type;                // Type de nœud (CMD, ARG, REDIRECTION, PIPE, etc.)
    char *data;              // Données du nœud (nom de la commande, nom du fichier, etc.)
    int input_fd;
    int output_fd;
    int pipe_fd[2];
    struct lr_node_s *next;       // Pointeur vers le nœud suivant dans la liste chaînée
    struct lr_node_s *child;      // Pointeur vers le premier nœud enfant dans la liste chaînée
}lr_node_t;

typedef struct lr_list_s{
    lr_node_t *root;
    lr_node_t *first;
    lr_node_t *last;
    struct lr_node_s *(*new)(type_t, char *);
    void (*add_first)(struct lr_list_s *, lr_node_t *);
    void (*add_last)(struct lr_list_s *, lr_node_t *);
}lr_list_t;

lr_list_t new_lr_list(void);

typedef struct parsing_s{
    char c;
    void (*ptr)(lr_list_t *, char *);
}parsing_t;

typedef struct mysh_s{
    lr_node_t *root;
}mysh_t;

void parse(char *);
void parse_pipe(lr_list_t *, char *);
void parse_semicolon(lr_list_t *, char *);
void parse_redirect(lr_list_t *, char *);

void loop();
void run();
void execute(char **command);
