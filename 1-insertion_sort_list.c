#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers in ascending order using the Insertion sort algorithm
 * @list: the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *next = NULL;
	listint_t *head = NULL;

	if (!list && !(*list))
		return;
	head = *list;
	current = head;
	while (current->next)
	{
		next = current->next;
		if (current->n > next->n)
			reverse_swap(list, next);
		else
			current = current->next;
	}
}

/**
 * reverse_swap - swap pointers towards the first node
 * @list: pointer to pointer to first node
 * @head: the pointer to start swapping towards the first node
*/
void reverse_swap(listint_t **list, listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *current = NULL;

	if (!head || !(head->next))
		return;
	while (head->prev)
	{
		current = head;
		prev = head->prev;
		if (prev->n > current->n)
		{
			swap_list(prev, current);
			head = current;
			if (head->prev == NULL)
				*list = head;
			print_list(*list);
		}
		else
			return;
	}
}

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
