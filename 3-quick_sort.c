#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void swap(int* a, int* b);
int partition(int array[], int low, int high, size_t size);
void quicksort_recur(int array[], int low, int hight, size_t size);

void swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int array[], int low, int high, size_t size)
{
	int pivot_value, i, j;

	pivot_value = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array,size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
void quicksort_recur(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort_recur(array, low, pivot - 1, size);
		quicksort_recur(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick Sort algorithm with Lomuto partitioning scheme.
 * The Lomuto partition scheme selects the last element in the current
 * partition as the pivot. The array is rearranged such that all elements
 * less than the pivot are placed before it, and all elements greater than
 * the pivot are placed after it. This process is applied recursively to
 * the left and right partitions of the array.
 *
 * Description:prints the array after each swap to display the sorting progress
 * @array: A pointer to the array of integers to be sorted.
 * @size: The size of the array.
 * Return: nothing
 *
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recur(array, 0, size - 1, size);
}
