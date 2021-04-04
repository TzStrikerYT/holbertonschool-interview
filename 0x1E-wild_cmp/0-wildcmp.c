#include "holberton.h"

/**
 * _strlen - Function that returns the lenght of the string using recursion
 * @s: string to calculate the lenght
 * Return: lenght of the string
 **/

int _strlen(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	s++;
	return (_strlen(s) + 1);
}

/**
 * _cmp - Function that helps to compare strings
 * @s1: first string
 * @s2: second string
 * @i: iterator for s1
 * @j: iterator for s2
 * @wc: wildcard on
 * @lwc: last wildcard
 * @len: length of s1
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 **/

int _cmp(char *s1, char *s2, int i, int j, int wc, int lwc, int len)
{
	if (s2[j] == '\0' && (s2[j - 1] == '*' || s2[j - 1] == s1[len - 1]))
		return (1);
	if (s2[j] == '*')
	{
		lwc = ++j;
		wc = 1;
		return (_cmp(s1, s2, i, j, wc, lwc, len));
	}
	if (s2[j] == s1[i])
	{
		i++;
		j++;
		wc = 0;
		return (_cmp(s1, s2, i, j, wc, lwc, len));
	}
	if (s1[i] != s2[j] && wc == 1)
	{
		if (s1[i] == '\0')
			return (0);
		i++;
		return (_cmp(s1, s2, i, j, wc, lwc, len));
	}
	if (s1[i] == '\0')
		return (0);
	if (s1[i] != s2[j] && wc == 0)
	{
		j = lwc;
		wc = 1;
		if (lwc == 0)
			return (0);
		return (_cmp(s1, s2, i, j, wc, lwc, len));
	}
	return (0);
}

/**
 * wildcmp - unction that compares two strings and can be considered identical.
 * @s1: string 1 to compare.
 * @s2: string 2 to compare, can contain the special character.
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */

int wildcmp(char *s1, char *s2)
{
	int i = 0, j = 0, wc = 1, lwc = 0, len;

	len = _strlen(s1);

	return (_cmp(s1, s2, i, j, wc, lwc, len));
}
