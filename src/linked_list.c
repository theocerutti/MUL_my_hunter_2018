/*
** EPITECH PROJECT, 2018
** Handle linked_list
** File description:
** Handle linked_list
*/

#include "../include/my_hunter.h"

l_list destroy_list(l_list list)
{
    node *temp = NULL;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    return (NULL);
}

l_list push(l_list list, sprite new_f)
{
    node *temp = list;
    node *new_node = malloc(sizeof(node));

    new_node->f = new_f;
    new_node->next = NULL;
    if (is_empty(list))
        return (new_node);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return (list);
}

l_list pop_index(l_list list, int n)
{
    int i = 0;
    node *current = list;
    node *temp_node = NULL;

    if (is_empty(list))
        return (NULL);
    if (n == 0) {
        list = list->next;
        return (list);
    }
    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL)
            return (list);
        current = current->next;
    }
    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
    return (list);
}

void print_list(l_list list)
{
    int i = 0;
    node *temp = list;

    if (is_empty(list) != 1) {
        for (i = 0; temp != NULL; i++) {
            my_put_nbr(i);
            temp = temp->next;
        }
        my_putstr("last node -> NULL\n");
    } else
        my_putstr("Empty list.");
}

int is_empty(l_list list)
{
    if (list == NULL) {
        return (1);
    } else
        return (0);
}
