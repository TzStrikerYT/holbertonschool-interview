#include "sandpiles.h"

/**
 * _print_grid - the a grid
 * @grid: grid to print
 * Return: Nothing
 */
void _print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * checker_estable - verificate if the sandpile is stable
 * @grid1: Sandpile to check
 * Return: 1 if not stable, 0 if is it.
 */
int checker_estable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
				return (1);
		}
	}
	return (0);
}

/**
 * sum_grid - sum two sandpiles
 * @grid1: The first grid to sum
 * @grid2: The second grid to sum
 * Return: Nothing
 */
void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * stabilizator - make stable the sandpile
 * @grid1: The grid to stabilizate.
 * @grid2: Helper grid
 * Return: Nothing
 */
void stabilizator(int grid1[3][3], int grid2[3][3])
{
	int i, j;
    /* Convert the second grid in 0 to save the changes of grid1*/
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = 0;
		}
	}

    /* Make the sum by slot */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				if (i - 1 >= 0)/* UP */
					grid2[i - 1][j] += 1;

				if (j - 1 >= 0)/* LEFT */
					grid2[i][j - 1] += 1;

				if (i + 1 <= 2)/* BOTTOM */
					grid2[i + 1][j] += 1;

				if (j + 1 <= 2)/* RIGHT */
					grid2[i][j + 1] += 1;

				grid1[i][j] -= 4;
			}
		}
	}

	sum_grid(grid1, grid2);
}

/**
 * sandpiles_sum - sum grid and return and stable grid
 * @grid1: First grid and printed
 * @grid2: Grid to make operations
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);

	while (checker_estable(grid1))
	{
		printf("=\n");
		_print_grid(grid1);
		stabilizator(grid1, grid2);
	}
}