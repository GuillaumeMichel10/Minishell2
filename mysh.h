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
#include <sys/stat.h>
#include <fcntl.h>

typedef struct node_s {
    struct node_s *next;
    struct node_s *prev;
    char **text;
    int len;
}node_t;

typedef struct list_s {
    int nb_nodes;
    node_t *first;
    node_t *last;
    void (*add)(struct list_s *, node_t *);
    node_t *(*new)(char **, int);
}list_t;

typedef struct mysh_s{
    list_t commands;
    list_t list_env;
    char **env;
    char *oldpwd;
}mysh_t;

list_t new_liked_list(void);

mysh_t setup(char **env);

void loop(mysh_t *);

void parse(mysh_t *mysh, char *input, size_t *n);

void run(mysh_t *mysh, char *lineptr);

void execute(mysh_t *mysh, node_t *node, const int nb_pipes, const int n);
int connect_pipe(int pipes[2][2], const int nb_pipes, const int n);
void close_pipe(int pipes[2][2], const int nb_pipes, const int n);
void swap_pipe(int **pipes);

int redirect_out(char **arguments);
int redirect_in(char **arguments);

int built_in(mysh_t *mysh, node_t *node);
int my_cd(mysh_t *mysh, node_t *node);
int my_setenv(mysh_t *mysh, node_t *node);

void my_env(mysh_t *mysh);

typedef struct built_in_t {
    char *name;
    int (*ptr)(mysh_t *, node_t *);
}built_in_t;
