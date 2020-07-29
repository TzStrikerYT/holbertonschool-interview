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
    listint_t *actual, *new_node;
    
    new_node = malloc(sizeof(listint_t));
    
    if (!new_node)
        return(NULL);
    
    new_node->n = number;
    
    if (!head)
    {
        new_node->next = NULL;
        *head = new_node;
        return (new_node);
    }

    if (!tmp || tmp->n >= number)
	{
		new->next = tmp;
		*head = new;
		return (new);
	}

    actual = *head;
    
    while (actual)
    {
        if (actual->n <= number && actual->next->n >= number)
        {
            new_node->next = actual->next;
            actual->next = new_node;
            return (new_node);
        }
        actual = actual->next;
    }
    return (NULL);
}
