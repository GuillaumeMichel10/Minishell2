/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_str_to_word_array
*/

#include "libmy.h"

char *extract_word(char **str, const char *delimiters)
{
    int len = my_strclen(*str, delimiters);
    char *cpy = malloc(sizeof(char) * (len + 1));

    cpy[len] = '\0';
    for (int i = 0; **str && !my_strchr(**str, delimiters); ++i) {
        cpy[i] = **str;
        ++(*str);
    }
    return (cpy);
}

char **my_str_to_word_array(char *str, const char *delimiters)
{
    char *ptr = str;
    int nb_lines = count_words(str, delimiters);
    char **tab = malloc(sizeof(char *) * (nb_lines + 1));

    tab[nb_lines] = NULL;
    for (int i = 0; i < nb_lines; ++i){
        tab[i] = extract_word(&ptr, delimiters);
        while (*ptr && my_strchr(*ptr, delimiters))
            ++ptr;
    }
    return (tab);
}
