#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm.
 * @array: A pointer to the array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing. The array is sorted in place.
 *
 * Description: The function repeatedly steps through the list, compares
 *              adjacent elements, and swaps them if they are in the wrong
 *              order. This process is repeated until the list is sorted.
 *              The algorithm is named "Bubble Sort" because the larger
 *              elements "bubble" to the top of the array after each pass.
 *              The time complexity of Bubble Sort is O(n^2) in the worst
 *              and average cases, making it inefficient for large datasets.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
	}
}

