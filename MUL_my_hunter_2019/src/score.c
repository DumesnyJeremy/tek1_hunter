/*
** EPITECH PROJECT, 2019
** csflm
** File description:
** oui
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_hunter.h"

int my_strlen(char const *str)
{
    int count = 0;
    if (str == NULL)
        return (0);
    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}

char *my_strcat(char *dest, char const *src, int n)
{
    int a = 0, b = 0;
    char *copy = malloc(sizeof(char) * (my_strlen(dest) + n + 1));
    if (dest != NULL) {
        while (dest[a] != '\0') {
    copy[a] = dest[a];
            a++;
        }
        free (dest);
    }
    while (b < n && src[b] != '\0') {
        copy[a] = src[b];
        a++;
        b++;
    }
    copy[a] = '\0';
    return (copy);
}

void my_put_nbr(int n, char **stock)
{
    int modulo;
    int a = 10;
    char test;

    if (n > -1)
    {
        if (n < 10) {
            test = 48 + n % 10;
            *stock = my_strcat(*stock, &test, 1);
        }
        else {
            modulo = (n % a);
            n = (n - modulo) / a;
            my_put_nbr(n, stock);
            test = modulo + 48;
            *stock = my_strcat(*stock, &test, 1);
        }
    }
}