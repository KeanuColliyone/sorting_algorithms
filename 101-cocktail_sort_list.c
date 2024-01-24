#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	do
	{
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
                		print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 * @list: Pointer to the pointer to the head of the list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	if (left == NULL || right == NULL || list == NULL || *list == NULL)
		return;

	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	if (right->next != NULL)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	left->prev = right;
	right->next = left;
}

