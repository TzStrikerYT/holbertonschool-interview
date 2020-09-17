#include "palindrome.h"
#include <stdlib.h>

/**
 * str_len - Give me the lenght of a string
 * @str: The string to count
 * Return: The lenght
 */
int str_len(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * my_reverse - Put the numbers in the correct order
 * @str: String to reverse
 * @len: String lenght
 * Return: Nothing
 */
void my_reverse(char str[], int len)
{
	int start, end;
	char temp;

	for (start = 0, end = len - 1; start < end; start++, end--)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}

/**
 * my_itoa - Convert the number to a string
 * @num: The number to convert
 * @str: The buffer to safe the converted number
 * Return: Return the converted string
 */
char *my_itoa(unsigned long int num, char *str)
{
	int i, j;
	char numbers[] = "0123456789";

	for (i = 0; num; i++)
	{
		j = num % 10;
		str[i] = numbers[j];
		str[i + 1] = '\0';
		num /= 10;
	}

	str[i] = '\0';

	my_reverse(str, i);

	return (str);
}
/**
 * is_palindrome - Verify if n number is palindrome
 * @n: The number to verify
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char buffer[1024];
	char *pali;
	int pali_len, i;

	pali = my_itoa(n, buffer);
	pali_len = str_len(pali);
	pali_len -= 1;

	for (i = 0; pali[i] || pali[pali_len]; i++, pali_len--)
		if (pali[i] != pali[pali_len])
			return (0);

	return (1);
}
