#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 *
 * The selection sort algorithm repeatedly selects the smallest element
 * from the unsorted portion of the array and swaps it with the first
 * element of the unsorted portion, thus moving the boundary of the
 * sorted portion one element to the right. This process is repeated
 * for all elements of the array.
 *
 * Time complexity:
 *   - Best case: O(n^2)
 *   - Average case: O(n^2)
 *   - Worst case: O(n^2)
 *
 * Space complexity: O(1) (in-place sorting)
 *
 * @array: A pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
	}
}
