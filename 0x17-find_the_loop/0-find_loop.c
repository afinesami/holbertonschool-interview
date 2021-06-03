#include "lists.h"

/**
 * find_listint_loop - Function finds the loop in a linked list
 * @head:	Pointer to head of the list
 * Return:	The address of the node where the loop starts, or NULL if there
 * is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1, *p2;

	if (!head)
		return (NULL);

	p2 = head->next;
	for (p1 = p2->next; p2 && p1 && p1->next; p1 = p1->next->next)
	{
		if (p2 == head || p1 == head)
			return (head);

		if (p2 == p1 && p1 != head)
		{
			head = head->next;
			p2 = head;
			p1 = head;
		}
		p2 = p2->next;
	}
	return (NULL);
}
