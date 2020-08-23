#include "lists.h"

/**
 * recursive - recursion for find a palindrome list.
 * @head: pointer thats point to the head of the linked list
 * @tmp: flag pointer to find palindrome
 * Return: NULL if the list isn't a palindrome, final if it's a palindrome.
 */

listint_t *recursive(listint_t **head, listint_t **tmp)
{
	listint_t *final = NULL;

	if (!*tmp)
		return (NULL);

	final = recursive(head, &(*tmp)->next);

	if (!(*tmp)->next && final == NULL)
	{
		if ((*head)->n == (*tmp)->n)
		{
			final = *head;
			return (final->next);
		}
		else
			return (NULL);
	}
	else if (final)
	{
		if (final->n == (*tmp)->n)
		{
			if (final->next)
				return (final->next);
			else
				return (final);
		}
		else
			return (NULL);
	}

	return (NULL);
}

/**
 * is_palindrome - check if a linked list is a palindrome.
 * @head: pointer thats point to the head of the linked list
 * Return: if the list isn't a palindrome, 1 if it's a palindrome.
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp, *value;

	tmp = *head;

	value = recursive(head, &tmp);

	if (!value)
		return (0);

	return (1);
}
