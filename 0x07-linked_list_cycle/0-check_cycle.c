#include "lists.h"

/**
 * check_cycle - check list
 * @list: list
 * Return: 1 or  0.
 */
int check_cycle(listint_t *list)
{
	listint_t *lent0;
	listint_t *lent1;

	if (list == NULL)
		return (0);
	lent0 = list;
	lent1 = list;

	while (lent0->next && lent1->next)
	{
		lent0 = lent0->next;
		lent1 = lent1->next->next;
		if (!lent1)
			return (0);
		if (lent0 == lent1)
			return (1);
	}
	return (0);
}
