#include "sort.h"

/**
 *sw - swaps 2 nodes in a doubly-linked list
 *@li1: address of first node
 *@li2: address of second node
 *
 *Return: void
 */

void sw(listint_t *li1, listint_t *li2)
{
	if (li1->prev)
		li1->prev->next = li2;
	if (li2->next)
		li2->next->prev = li1;
	li1->next = li2->next;
	li2->prev = li1->prev;
	li1->prev = li2;
	li2->next = li1;
}

/**
 *go_reverse- function that sorts from the tail back
 *
 *@he: head of list
 *@ta: tail of the list
 *@li: original head of the list
 *
 *Return: new head of the list
 */

listint_t *go_reverse(listint_t *he, listint_t *ta, listint_t *li)
{
	while (ta && ta->prev)
	{
		if (ta->n < ta->prev->n)
		{
			sw(ta->prev, ta);
			if (ta->prev == NULL)
				li = ta;
			print_list(li);
		}
		else
			ta = ta->prev;
		if (ta->prev == NULL)
			he = ta;
	}
	return (he);
}

/**
 *cocktail_sort_list - sorts linked list using cocktail shaker sort
 *
 *@list: doubly linked list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ta, *he, *len;
	int i = 0, j = 0, swa = 1;

	if (!list || !*list)
		return;
	len = *list;
	for (i = 0; len; i++)
	{
		len = len->next;
	}
	if (i < 2)
		return;
	he = *list;
	while (j < i)
	{
		swa = 0;
		while (he && he->next)
		{
			if (he->n > he->next->n)
			{
				sw(he, he->next);
				swa++;
				if (he->prev->prev == NULL)
					*list = he->prev;
				print_list(*list);
			}
			else
				he = he->next;
			if (he->next == NULL)
				ta = he;
		}
		he = go_reverse(he, ta, *list);
		*list = he;
		j++;
	}
}
