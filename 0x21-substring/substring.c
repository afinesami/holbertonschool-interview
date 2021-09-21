#include "substring.h"
/**
 * cmpfunc - compare tow values
 * @a: first value
 * @b: second value
 * Return: substraction
 **/
int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
/**
 * check - chek if all words are continous
 * @aux_indx: array with index for ever word
 * @wordlen: word size
 * @idx_len: aux_indx size
 * Return: index firt word or zero
 **/
int check(int *aux_indx, int wordlen, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_indx[i + 1] - aux_indx[i]  != wordlen)
			return (0);
	}
	return (1);
}
/**
 * search - search words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * Return: array with size of substring (strstr return) for every word or NULL
 **/
int *search(char const *s, char const **words, int nb_words)
{
	int *aux_indx, i, j;
	char *aux;
	int len;

	aux_indx = malloc((sizeof(int) * nb_words));
	if (!aux_indx)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_indx);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (len == aux_indx[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
				if (!aux)
				{
					free(aux_indx);
					return (NULL);
				}
				len = (int)strlen(aux);
				aux_indx[i] = len;
				continue;
			}

		}
		aux_indx[i] = len;
	}

	return (aux_indx);

}
/**
 * find_substring - search words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * @n: return size
 * Return: array with index for every word or NULL
 *
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indx, *aux_indx, wordlen, j, diff, s_len, f_indx, tmp;

	*n = 0;
	wordlen = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		/*strstr for every word*/
		aux_indx = search(s, words, nb_words);
		if (!aux_indx)
			break;
		/* sort size of substrings */
		qsort(aux_indx, nb_words, sizeof(int), cmpfunc);
		/* are the words next each other? */
		f_indx = check(aux_indx, wordlen, nb_words);
		tmp = aux_indx[nb_words - 1];
		free(aux_indx);
		/* if a valid substring was found*/
		if (f_indx == 1)
		{
			diff = s_len - tmp;
			if (*n == 0 || diff != indx[*n - 1])
			{
				if (*n == 0)
				{
					indx = malloc((sizeof(int)));
					if (!indx)
						return (NULL);
				}
				else
					indx = realloc(indx, sizeof(int) * (*n + 1));
				indx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (indx);
}
