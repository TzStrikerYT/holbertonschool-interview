#include "search.h"

/**
 * find_last - Find the last element of the list
 * @node: pointer to the next list to search in
 * Return: The last node of the list
 */
skiplist_t *find_last(skiplist_t *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

/**
 * check_next -  search a value
 * @node: pointer to the next list to search in
 * @value: value to search for
 * Return: first node where value is located or NULL
 */
skiplist_t *check_next(skiplist_t *node, int value)
{
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index,
		       node->n);
		if (node->n == value)
			return (node);

		node = node->next;
	}
	return (NULL);
}

/**
 * linear_skip - searches a value in a sorted skip int list
 * @list: head of the skip list to search in
 * @value: value to search for
 * Return: first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *last;

	if (!list)
		return (NULL);

	while (list)
	{
		if (list->express == NULL)
		{
			last = find_last(list);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       list->index, last->index);
			return (check_next(list, value));
		}

		if (list->express->n >= value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			       list->express->index, list->express->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       list->index, list->express->index);
			return (check_next(list, value));
		}
		list = list->express;
		printf("Value checked at index [%lu] = [%d]\n", list->index,
		       list->n);
	}
	return (NULL);
}
