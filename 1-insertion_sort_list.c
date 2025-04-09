#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 *
 * Return: Nothing. The list is sorted in place.
 *
 * Description: This function sorts a doubly linked list using the Insertion
 *              Sort algorithm. Insertion sort works by iterating through the
 *              list and inserting each element in its correct position by
 *              comparing it with the previous nodes. The algorithm swaps the
 *              nodes themselves,without modifying the integer `n` of any node.
 *              The process continues until the entire list is sorted.Insertion
 *              Sort has a time complexity of O(n^2) in the worst case, which
 *              occurs when the list is reversed,and O(n) in the best case when
 *              the list is already sorted.
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current, *next_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			/*Swap current and current->prev*/
			listint_t *prev_node = current->prev;
			listint_t *prev_prev_node = prev_node->prev;

			/*Update the links to swap nodes*/
			if (prev_prev_node)
				prev_prev_node->next = current;
			current->prev = prev_prev_node;

			prev_node->prev = current;
			prev_node->next = current->next;
			if (current->next)
				current->next->prev = prev_node;

			current->next = prev_node;

			/*If current is now the head of the list, update the head*/
			if (!current->prev)
				*list = current;

			/*Print the list after the swap*/
			print_list(*list);
		}
		current = next_node;
	}
}
