#include "sort.h"

/**
 * sw - swap to doubly linked list elements
 * @a: left element
 * @b: right element
 * @list: all doubly linked list
 * Return: pointer to a element (actual)
 */

listint_t *sw(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->prev)
		(a->prev)->next = b;
	else
		*list = b, b->prev = NULL;
	if ((b->next))
		(b->next)->prev = a;
	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	b->next = a;
	return (a);
}

/**
 * insertion_sort_list - sorts list in ascending order
 * @list: a doubly linked list of integers to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *actual;
	listint_t *pr, *ba;

	if (!list || !(*list) || !(*list)->next)
		return;

	actual = (*list)->next;
	while (actual)
	{
		pr = actual->prev;
		ba = actual;
		while (ba->prev && ba->n < pr->n)
		{
			actual = sw(pr, ba, list);
			print_list(*list);
			if (!ba->prev)
				break;
			pr = ba->prev;
		}
		actual = actual->next;
		pr = pr->next;
	}
}
