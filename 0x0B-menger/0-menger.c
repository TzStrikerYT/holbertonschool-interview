#include "menger.h"
#include <math.h>

/**
 * verify_module - Checks if the module of indices are
 * (1, 1) then square is blank
 * @i: Row Index
 * @j: Column Index
 * Return: 1 if (1, 1), 0 otherwise
 */

int verify_module(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}

/**
 * menger - Entry point
 * @level: level of the Menger Sponge to draw
 * Return: Nothing
 */
void menger(int level)
{
	int i, j, limit = pow(3, level);

	if (level < 0)
		return;

	for (i = 0; i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			verify_module(i, j) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
