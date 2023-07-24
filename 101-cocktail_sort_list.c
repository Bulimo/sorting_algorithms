#include "sort.h"

/**
 * swap_list - swaps two doubly linked list nodes
 * @current: first node
 * @next: second node
*/
void swap_list(listint_t *current, listint_t *next)
{
	current->next = next->next;
	if (next->next)
		next->next->prev = current;
	next->next = current;
	next->prev = current->prev;
	if (current->prev)
		current->prev->next = next;
	current->prev = next;
}


/**
 * sort_forward - bubble sort the list in forward direction
 * @start: the node to start at
 * @stop: the node to stop sorting
 * @list: address of the pointer to first node
*/
void sort_forward(listint_t *start, listint_t *stop, listint_t **list)
{
	listint_t *iter = NULL;
	listint_t *next = NULL;
	int swapped = 0;

	puts("sort forward called");
	if (!list || !start || start == stop)
		return;

	iter = start;
	while (iter->next && (iter != stop))
	{
		next = iter->next;
		if (iter->n > next->n)
		{
			swap_list(iter, next);
			swapped++;
			if (next->prev == NULL)
				*list = next;
			print_list(*list);
		}
		else
			iter = iter->next;
	}
	if (iter == NULL)
		iter = iter->prev;
	if (swapped)
		sort_reversed(iter, start, list);
	else
		return;
}

/**
 * sort_reversed - bubble sort the list in reversed direction
 * @start: the node to start at
 * @stop: the node to stop sorting
 * @list: address of the pointer to first node
*/
void sort_reversed(listint_t *start, listint_t *stop, listint_t **list)
{
	listint_t *iter = NULL;
	listint_t *prev = NULL;
	int swapped = 0;

	puts("sort reversed called");
	if (!list || !start || start == stop)
		return;

	iter = start;
	while (iter->prev && (iter != stop))
	{
		prev = iter->prev;
		if (iter->n < prev->n)
		{
			swap_list(prev, iter);
			swapped++;
			if (iter->prev == NULL)
				*list = iter;
			print_list(*list);
		}
		else
			iter = iter->prev;
	}
	if (iter == stop)
		iter = iter->next;
	if (swapped)
		sort_forward(iter, start, list);
	else
		return;
}

/**
 * cocktail_sort_list - sorts a list using the Cocktail Shaker sort
 * @list: pointer to pointer to the first node
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *iter = NULL;
	listint_t *next = NULL;
	listint_t *stop = NULL;
	int swapped = 0;

	if (!list || !(*list) || !((*list)->next))
		return;

	iter = *list;
	while (iter->next && (iter != stop))
	{
		next = iter->next;
		if (iter->n > next->n)
		{
			swap_list(iter, next);
			swapped++;
			if (next->prev == NULL)
				*list = next;
			print_list(*list);
		}
		else
			iter = iter->next;
	}
	if (iter == NULL)
		iter = iter->prev;
	if (swapped)
		sort_reversed(iter, *list, list);
	else
		return;
}
