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
    char *str;
    int len;
}node_t;

typedef struct list_s {
    int nb_nodes;
    node_t *first;
    node_t *last;
    void (*add)(struct list_s *, node_t *);
    node_t *(*new)(char **, int);
    void (*pop)(struct list_s *, node_t *);
}list_t;

list_t *new_liked_list(void);

typedef struct heap_s {
    list_t **array;
    int capacity;
    int size;
    void (*add)(struct heap_s *, list_t *);
    void (*pop)(struct heap_s *);
}heap_t;

heap_t new_heap(int capacity);

typedef struct mysh_s{
    heap_t commands;
    list_t *list_env;
    char **env;
    char *oldpwd;
    char *home;
    char **path;
    int error;
    bool exit;
}mysh_t;

mysh_t setup(char **env);

int loop(mysh_t *mysh);

void parse(mysh_t *mysh, char *input);
int valid_input(mysh_t *mysh, node_t *node);

void run(mysh_t *mysh, list_t *list);

void execute(mysh_t *mysh, node_t *node, const int nb_pipes, const int n);
void connect_pipe(int pipes[2][2], const int nb_pipes, const int n);
void close_pipe(int pipes[2][2], const int nb_pipes, const int n);
void swap_pipe(int **pipes);

int redirect_out(char **arguments);
int redirect_in(mysh_t *mysh, char **arguments);

int built_in(mysh_t *mysh, node_t *node);
int is_built_in(char *str);

int my_cd(mysh_t *mysh, node_t *node);
int my_setenv(mysh_t *mysh, node_t *node);
int my_unsetenv(mysh_t *mysh, node_t *command);
int my_exit(mysh_t *mysh, node_t *command);
void my_update_env(mysh_t *mysh);
int my_echo(mysh_t *mysh, node_t *node);
void my_env(mysh_t *mysh);

void erase(char **text, size_t n);

typedef struct built_in_t {
    char *name;
    int (*ptr)(mysh_t *, node_t *);
}built_in_t;
