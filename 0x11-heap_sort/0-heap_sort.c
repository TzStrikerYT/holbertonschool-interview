#include "sort.h"

/**
 * swap - Swaps the elements
 * @a: first element
 * @b: Second element
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Builds a heap out of the array
 * @arr: the array
 * @n: heap size
 * @i: root index
 * @size: size of arr
 */

void heapify(int arr[], int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, n, largest, size);
	}
}

/**
 * heap_sort - heap sort function
 * @arr: the array that will be sorted
 * @size: size of array
 */

void heap_sort(int arr[], size_t size)
{
	int i = 0;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		if (i != 0)
			print_array(arr, size);
		heapify(arr, i, 0, size);
	}
}
