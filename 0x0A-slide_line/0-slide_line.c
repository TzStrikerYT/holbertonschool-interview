#include <stddef.h>
#include <stdio.h>
#include "slide_line.h"


/**
 * put_together - Sum a line that wil be slided of a specific direction
 * @line: line points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to merge the elements
 */
void put_together(int *line, size_t size, int direction)
{
	size_t i, j, tmp;

	if (direction == 0) /* LEFT */
	{
		for (i = 0; i < size; i++)
			for (j = i + 1;  j < size; j++)
			{
				if (line[i] < line[j] && line[i] != 0)
					break;
				else if (line[i] == 0 && line[j] != 0)
				{
					/*Put all together*/
					tmp = line[i];
					line[i] = line[j];
					line[j] = tmp;
				}
			}
	}
	else if (direction == 1) /* RIGHT */
	{
		for (i = size - 1; (int)i >= 0; i--)
			for (j = i - 1;  (int)j >= 0; j--)
			{
				if (line[i] < line[j] && line[i] != 0)
					break;
				else if (line[i] == 0 && line[j] != 0)
				{
					/*Put all together*/
					tmp = line[i];
					line[i] = line[j];
					line[j] = tmp;
				}
			}
	}
}

/**
 * merge_line - Sum a line that wil be slided of a specific direction
 * @line: line points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to merge the elements
 */
void merge_line(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == 0) /* LEFT */
	{
		for (i = 0; i < size; i++)
			for (j = i + 1;  j < size; j++)
			{
				if (line[i] == line[j])
				{
					/* Merge */
					line[i] = line[i] + line[j];
					line[j] = 0;
					break;
				}
			}
	}
	else if (direction == 1) /* RIGHT */
	{
		for (i = size - 1; (int)i >= 0; i--)
			for (j = i - 1;  (int)j >= 0; j--)
			{
				if (line[i] == line[j])
				{
					/* Merge */
					line[i] = line[i] + line[j];
					line[j] = 0;
					break;
				}
			}
	}
	put_together(line, size, direction);
}

/**
 * slide_line - Sum a line that wil be slided of a specific direction
 * @line: line points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to merge the elements
 * Return: 1 if is succes or 0 if it fails
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	if (direction == 0 || direction == 1)
	{
		put_together(line, size, direction);
		merge_line(line, size, direction);
	}
	else
		return (0);

	return (1);
}
