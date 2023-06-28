#include "sort.h"

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort
 *                      algorithm.
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tmp;
int swapped = 1;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (swapped)
{
swapped = 0;
tmp = *list;
while (tmp->next != NULL)
{
if (tmp->n > tmp->next->n)
{
swap_nodes(tmp, tmp->next, list);
print_list(*list);
swapped = 1;
}
else
tmp = tmp->next;
}
if (!swapped)
break;
swapped = 0;
tmp = tmp->prev;
while (tmp->prev != NULL)
{
if (tmp->n < tmp->prev->n)
{
swap_nodes(tmp->prev, tmp, list);
print_list(*list);
swapped = 1;
}
else
tmp = tmp->prev;
}
}
}

/**
 * swap_nodes - function to swap two given nodes in a doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 * @head: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **head)
{
listint_t *tmp = node2->next;

if (node1->prev == NULL)
{
*head = node2;
node2->prev = NULL;
}
else
{
node1->prev->next = node2;
node2->prev = node1->prev;
}

if (node2->next == NULL)
{
node1->next = NULL;
}
else
{
node2->next->prev = node1;
node1->next = node2->next;
}
}
