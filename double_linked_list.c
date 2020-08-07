#include "includes/structures.h"

list_t *new_list(void)
{
    list_t *new_list = malloc(sizeof(new_list));

    if (new_list == NULL)
        return new_list;
    new_list->length = 0;
    new_list->end = NULL;
    new_list->beg = NULL;
    return new_list;
}

list_t *add_end_of_list(list_t *list, int element)
{
    node_t *new_node = malloc(sizeof(new_node));

    if (list == NULL)
        return list;
    new_node->next = NULL;
    new_node->data = element;
    if (list->end == NULL) {
        new_node->previous = NULL;
        list->beg = new_node;
        list->end = new_node;
    } else {
        list->end->next = new_node;
        new_node->previous = list->end;
        list->end = new_node;
    }
    list->length += 1;
    return list;
}

list_t *add_beg_of_list(list_t *list, int element)
{
    node_t *new_node = malloc(sizeof(new_node));

    if (list == NULL)
        return list;
    new_node->next = list->beg;
    new_node->data = element;
    if (list->end == NULL) {
        new_node->previous = NULL;
        list->beg = new_node;
        list->end = new_node;
    } else {
        list->end->next = new_node;
        new_node->previous = NULL;
        list->end = new_node;
    }
    list->length += 1;
    return list;
}

list_t *add_in_list(list_t *list, int element, int place)
{
    node_t *tmp;
    int count;
    node_t *new_node;

    if (list == NULL)
        return list;
    tmp = list->beg;
    for (count = 1; count <= place && tmp != NULL; tmp = tmp->next, i++) {
        if (place == count && tmp->next == NULL) {
            list = add_end_of_list(list, element);
            return list;
        }
        if (place == count && tmp->next != NULL) {
            list = add_beg_of_list(list, element);
            return list;
        }
        if (place == count) {
            new_node = malloc(sizeof(new));
            new_node->val = element;
            tmp->next->prev = new_node;
            tmp->prev->next = new_node;
            new_node->prev = tmp->prev;
            new_node->next = tmp;
            list->length += 1;
        }
    }
    return list;
}
