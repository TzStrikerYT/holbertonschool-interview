#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *bunny = list, *turtle = list;

	if (!list)
		return (0);

	while (turtle->next && bunny->next)
	{
		turtle = turtle->next;

		if (bunny->next->next)
			bunny = bunny->next->next;
		else
			break;

		if (bunny->n == turtle->n)
			return (1);
	}
	return (0);
}
