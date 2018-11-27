/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Manage open/close/write/copy in a file. -> it's for hightest score save.
*/

#include "../include/my_hunter.h"

char *my_itoa(int nb)
{
    char *new_str = malloc(sizeof(char) * 100);
    int nb_digit = 0;
    int multi = 1;
    int i = 0;

    if (nb == 0) {
        nb_digit = 1;
        multi *= 10;
    }
    for (long nb_s = nb; nb_s > 0; nb_s /= 10, multi *= 10)
        nb_digit += 1;
    multi /= 10;
    for (i = 0; i != nb_digit; i++, multi /= 10)
        new_str[i] = (nb / multi % 10) + '0';
    new_str[i] = '\0';
    return (new_str);
}

int my_atoi(char *str)
{
    int nb_digits = 0;
    int result = 0;
    int multi = 1;
    int index = 0;

    for (nb_digits = 0; str[nb_digits] != '\0'; nb_digits++);
    if (str[0] == '-') {
        index += 1;
        nb_digits -= 1;
    }
    for (int i = 0; i != nb_digits - 1; multi *= 10, i++);
    for (index; str[index] != '\0'; index++) {
        result += (str[index] - '0') * multi;
        multi /= 10;
    }
    if (str[0] == '-')
        result *= -1;
    return (result);
}

int get_highest_score(char *path_file)
{
    FILE *file = NULL;
    int highest_score = 0;
    char score_str[50];

    file = fopen(path_file, "r+");
    if (file == NULL)
        exit(84);
    fgets(score_str, 50, file);
    highest_score = my_atoi(score_str);
    fclose(file);
    return (highest_score);
}

void put_highest_score(char *path_file, int score)
{
    FILE *file = NULL;
    char *score_str = malloc(sizeof(char) * 50);
    int score_file = get_highest_score(path_file);

    if (score > score_file) {
        file = fopen(path_file, "w");
        if (file == NULL)
            exit(84);
        score_str = my_itoa(score);
        fputs(score_str, file);
        fclose(file);
    }
}