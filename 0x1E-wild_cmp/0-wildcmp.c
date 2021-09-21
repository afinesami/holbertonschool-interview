#include "holberton.h"
/**
 * _strlen_recursion - lenght
 * @s: char
 * Return: lenght
 **/
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	s++;
	return (_strlen_recursion(s) + 1);
}
/**
 * comp - compares
 * @s1: char
 * @s2: char
 * @i: iterator for s1
 * @j: iterator for s2
 * @wc: wildcard on
 * @lastwc: last wildcard
 * @len: length s1
 * Return: boolean
 **/

int comp(char *s1, char *s2, int i, int j, int wc, int lastwc, int len)
{
	if (s2[j] == '\0' && (s2[j - 1] == '*' || s2[j - 1] == s1[len - 1]))
		return (1);
	if (s2[j] == '*')
	{
		lastwc = ++j;
		wc = 1;
		return (comp(s1, s2, i, j, wc, lastwc, len));
	}
	if (s2[j] == s1[i])
	{
		i++;
		j++;
		wc = 0;
		return (comp(s1, s2, i, j, wc, lastwc, len));
	}
	if (s1[i] != s2[j] && wc == 1)
	{
		if (s1[i] == '\0')
			return (0);
		i++;
		return (comp(s1, s2, i, j, wc, lastwc, len));
	}
	if (s1[i] == '\0')
		return (0);
	if (s1[i] != s2[j] && wc == 0)
	{
		j = lastwc;
		wc = 1;
		if (lastwc == 0)
			return (0);
		return (comp(s1, s2, i, j, wc, lastwc, len));
	}
	return (0);
}

/**
 * wildcmp - 1 if the strings can be considered identical
 * @s1: char 1
 * @s2: char 2
 * Return: Boolean
 */
int wildcmp(char *s1, char *s2)
{
	int i = 0, j = 0, wc = 1, lastwc = 0, len;

	len = _strlen_recursion(s1);

	return (comp(s1, s2, i, j, wc, lastwc, len));
}
