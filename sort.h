#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);

void merge_sub(int *sub, int *buff, size_t fr, size_t mid,
			   size_t ba);
void merge_recur(int *sub, int *buff, size_t fr, size_t ba);
void merge_sort(int *array, size_t size);

void swa_i(int *int1, int *int2);
void max_heap(int *arr, size_t len, size_t base, size_t root);
void heap_sort(int *array, size_t size);

int mmax(int *arr, int size);
void radix_sort_count(int *arr, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);

int hoare_part(int *arr, size_t size, int lt, int rt);
void hoare_sort(int *arr, size_t size, int lt, int rt);
void quick_sort_hoare(int *array, size_t size);

#endif /*SORT_H*/
