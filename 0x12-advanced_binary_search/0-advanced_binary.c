#include "search_algos.h"


/**
 * print_array - prints an array
 * @left: first el of the array
 * @right: last el of the array
 * @array: pointer to aim to the first element
 **/
void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%i, ", array[left]);
		left++;
	}
	printf("%i\n", array[left]);
}

/**
 * recursive_binary - recursive function that search a number
 * in a sorted array of integers
 * @array: is a pointer to the first element of the array
 * @value: is the value to search for
 * @left: left to the stack
 * @right: rigth to the stack
 * Return:the index or -1 if fails
 **/
int recursive_binary(int *array, int left, int right, int value)
{
	int middle;

	print_array(array, left, right);
	middle = (right - left) / 2 + left;
	if (left == right)
		return (-1);
	if (array[middle] == value && array[middle - 1] != value)
		return (middle);
	if (array[middle] >= value)
		return (recursive_binary(array, left, middle, value));
	if (array[middle] <= value)
		return (recursive_binary(array, middle + 1, right, value));
	return (-1);
}

/**
 * advanced_binary - binary algorithm
 * @array: is a pointer to the first element of the array
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return:the index or -1 if fails
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_binary(array, 0, size - 1, value));
}
