#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * function that inserts a new node in a sorted linked list
 * @head: head of the list
 * @number: number tha shod be inserted
 * Return: node of list, or NULL if op fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *actual = *head;
	listint_t *new, *actual2;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (!actual || actual->n >= number)
	{
		new->next = actual;
		*head = new;
		return (new);
	}

	actual2 = actual->next;
	while (actual && actual2 && (actual2->n < number))
	{
		actual = actual->next;
		actual2 = actual->next;
	}

	actual->next = new;
	new->next = actual2;
	return (new);
}