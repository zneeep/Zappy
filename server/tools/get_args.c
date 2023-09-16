/*
** EPITECH PROJECT, 2023
** Greg_zappy
** File description:
** get_args
*/

#include "tools.h"

char *get_arg(char *line, char delim)
{
    char *arg = NULL;
    int i = 0;
    int j = 0;
    int size = strlen(line);

    for (; line[i] != '\0' && line[i] != delim; i++);
    size -= i;
    arg = calloc(1, sizeof(char) * (size + 1));
    for (i++; line[i] != '\0' && line[i] != delim; i++)
        arg[j++] = line[i];
    arg[j] = '\0';
    return arg;
}

char **get_args(char **tab, char *buf, char *separators)
{
    int size = 0;
    char *strToken = strtok(buf, separators);

    while (strToken != NULL) {
        tab = realloc(tab, (size + 1) * sizeof(char *));
        strToken = get_arg(strToken, '\"');
        tab[size] = calloc(1, strlen(strToken) + 1);
        strcpy(tab[size], strToken);
        size++;
        strToken = strtok(NULL, separators);
    }
    tab = realloc(tab, (size + 1) * sizeof(char *));
    tab[size + 1] = NULL;
    return tab;
}

int get_size_tab(char *str, char delim)
{
    int size = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == delim)
            size++;
    return (size + 2);
}

char *get_first_arg(char *name, char delim)
{
    int size = 0;
    char *res = NULL;

    for (; name[size] && name[size] != delim; size++);
    res = calloc(1, sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
        res[i] = name[i];
    res[size] = '\0';
    return res;
}

char **get_tab(char **tab, char *str, const char delim)
{
    int count = 0;
    const char *start = str;
    size_t len = strlen(str);

    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delim || str[i] == '\0') {
            size_t sub_len = i - (start - str);
            char *sub_str = (char *)malloc((sub_len + 1) * sizeof(char));
            strncpy(sub_str, start, sub_len);
            sub_str[sub_len] = '\0';
            tab[count++] = sub_str;
            start = str + i + 1;
        }
    }
    tab[count] = NULL;
    return tab;
}
