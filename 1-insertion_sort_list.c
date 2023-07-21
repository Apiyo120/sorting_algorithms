#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort.
 *
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *unsorted, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	sorted = *list;
	unsorted = sorted->next;

	while (unsorted)
	{
		temp = unsorted;
		unsorted = unsorted->next;

		while (temp->prev && temp->n < temp->prev->n)
		{
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next->prev = temp;
			print_list(*list);
		}
	}
}
