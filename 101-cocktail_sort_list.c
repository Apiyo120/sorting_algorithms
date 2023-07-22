#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 *
 * @list: Pointer to the doubly linked list.
 * @left: The left node to be swapped.
 * @right: The right node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;

	if (right->next != NULL)
		right->next->prev = left;

	right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using Cocktail Shaker sort algorithm.
 *
 * @list: Pointer to the doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp, *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (temp = *list; temp->next != end; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		end = temp->prev;

		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
