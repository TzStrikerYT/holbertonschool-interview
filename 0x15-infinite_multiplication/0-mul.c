#include "holberton.h"

/**
 * main - Prints the product of two numbers from the command line.
 * @argc: The int number of arguments.
 * @argv: An array of string arguments.
 * Return: Success(0) or another exit code.
 */
int main(int argc, char *argv[])
{
	char *f = argv[1];
	char *s = argv[2];

	if (argc != 3 || !isNumber(f) || !isNumber(s))
	{
		printf("Error\n");
		exit(98);
	}
	if (*f == 48 || *s == 48)
		printf("0\n");
	else
		multiply(s, f);
	return (0);
}

/**
 * multiply - Computes and prints the product of two numbers.
 * @a: A string number to multiply with b.
 * @b: A string number to multiply with a.
 */
void multiply(char *a, char *b)
{
	int i, len1, len2, total, adigit, bdigit, res = 0, tmp;
	int *ptr;

	len1 = _strlen(a);
	len2 = _strlen(b);
	tmp = len2;
	total = len1 + len2;
	ptr = _calloc(sizeof(int), (len1 + len2));
	for (len1--; len1 >= 0; len1--)
	{
		adigit = a[len1] - '0';
		res = 0;
		len2 = tmp;
		for (len2--; len2 >= 0; len2--)
		{
			bdigit = b[len2] - '0';
			res += ptr[len2 + len1 + 1] + (adigit * bdigit);
			ptr[len1 + len2 + 1] = res % 10;
			res /= 10;
		}
		if (res)
			ptr[len1 + len2 + 1] = res % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}
/**
 * isNumber - Checks if a string is a number.
 * @c: input string
 * Return: 0 if false, 1 if true
 */
int isNumber(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

/**
 * _strlen - Computes the length of a string.
 * @s: The string to measure.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	char *p = s;

	while (*s)
		s++;
	return (s - p);
}

/**
 * _memset - Fills memory with a constant byte.
 * @s: The memory to fill.
 * @b: The constant byte.
 * @n: The number of bytes to fill.
 * Return: A pointer to the filled memory.
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n--)
		*s++ = b;
	return (ptr);
}

/**
 * _calloc - Allocates memory for an array.
 * @nmemb: The number of elements.
 * @size: The size of each element.
 * Return: A pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (!nmemb || !size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	_memset(ptr, 0, size * nmemb);
	return (ptr);
}
