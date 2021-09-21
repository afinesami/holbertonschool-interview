#include <stdlib.h>
#include <stdio.h>

#include "substring.h"

int main(int ac, char const **av)
{
	char const *s;
	char const **words;
	int nb_words;
	int *indices;
	int n;
	int i;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s <string> [word [word2 ...]]\n", av[0]);
		return (EXIT_FAILURE);
	}

	s = av[1];
	words = av + 2;
	nb_words = ac - 2;

	indices = find_substring(s, words, nb_words, &n);

	printf("Indices -> [");
	for (i = 0; i < n; i++)
	{
		if (i)
			printf(", ");
		printf("%d", indices[i]);
	}
	printf("]\n");

	return (EXIT_SUCCESS);
}
