/*
** EPITECH PROJECT, 2023
** my
** File description:
** lib_my
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void my_putchar(const char c);
void my_puterr(const char *str);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_isneg(int nb);
void my_swap(void **a, void **b);
int my_strlen(char const *str);
int is_digit(char c);
int my_atoi(const char *str);
char *my_strcpy(const char *str);
int my_strcmp(const char *str1, const char *str2);
int my_nbrlen(int nb);
int my_strclen(const char *str, const char *delimiters);
char *my_strccpy(const char *str, const char *delimiters);
int my_strchr(const char c, const char *delimiters);
int count_words(const char *str, const char *delimiters);
char **my_str_to_word_array(char *str, const char *delimiters, size_t *n);
