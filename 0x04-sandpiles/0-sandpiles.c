#include "sandpiles.h"

/**
 * _print_grid - final grid result
 * @grid: final result of the grid step
 * Return: void statement
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
 * @grid1: array to check
 * Return: 1 on error, 0 if is stable array
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
 * @grid1: first bidimensional array
 * @grid2: second bidimensional array
 * Return: void statement
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
 * stabilizator - make that sanpile will be stable
 * @grid1: first bidimensional array
 * @grid2: second bidimensional array
 * Return: void statement
 */
void stabilizator(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				if (i - 1 >= 0)/* Up */
					grid2[i - 1][j] += 1;
					
				if (i + 1 <= 2)/* Down */
					grid2[i + 1][j] += 1;	

				if (j - 1 >= 0)/* Left*/
					grid2[i][j - 1] += 1;

				if (j + 1 <= 2)/* Rigth */
					grid2[i][j + 1] += 1;

				grid1[i][j] -= 4;
			}
		}
	}

	sum_grid(grid1, grid2);
}

/**
 * sandpiles_sum - sum a grid and return an stable grid
 * @grid1: First bidimensinal array
 * @grid2: second bidimensinal array
 * Return: void statement
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