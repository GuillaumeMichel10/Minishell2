/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_strchr
*/

int my_strchr(const char c, const char *delimiters)
{
    if (c == '\0')
        return (0);

    for (int k = 0; delimiters[k]; ++k)
        if (delimiters[k] == c)
            return (1);

    return (0);
}
