#include "binary_trees.h"

/**
 * bisearch - Function that builds a binary tree
 * @array: poitnter to array
 * @start: pointer to start
 * @end: pointer to end
 * @p_node: parent node
 * Return: pointer to header
 **/
avl_t *bisearch(int *array, int start, int end, avl_t *p_node)
{
	int middle;
	avl_t *node;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = array[middle];
	node->p_node = p_node;
	node->left = bisearch(array, start, middle - 1, node);
	node->right = bisearch(array, middle + 1, end, node);
	return (node);
}

/**
 *sorted_array_to_avl - Builds a binary tree with a sorted array
 * @array: pointer to array
 * @size: size of the array
 * Return: Result of bisearch function
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (bisearch(array, 0, size - 1, NULL));
}
