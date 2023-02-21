#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list in ascending order
 *                       using insertion sort
 * @list: pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *nxt, *current;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	head = *list;
	nxt = head->next;
	while (nxt != NULL)
	{
		current  = nxt->prev;
		while (current != NULL)
		{
			if (nxt->n < current->n)
			{
				if (nxt->next != NULL)
				{
					nxt->next->prev = current;
				}
				if (current->prev != NULL)
				{
					current->prev->next = nxt;
				}
				else
				{
					head = nxt;
					*list = head;
				}
				nxt->prev = current->prev;
				current->next = nxt->next;
				nxt->next = current;
				current->prev = nxt;
				print_list(head);
			}
			current = current->prev;
		}
		nxt = nxt->next;
	}
}
