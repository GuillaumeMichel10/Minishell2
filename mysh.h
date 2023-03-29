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


typedef struct mysh_s{
}mysh_t;

void loop();

void parse(char *input, char ****commands, size_t *n);

void run(char ***command, size_t nb_pipes);

void execute(char **command, const int nb_pipes, const int n);
int connect_pipe(int pipes[2][2], const int nb_pipes, const int n);
void close_pipe(int pipes[2][2], const int nb_pipes, const int n);
void swap_pipe(int **pipes);

int redirect_out(char **command);
