#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: Number to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *prev;
	listint_t *current;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	current = *head;
	if (*head == NULL)
		*head = new;
	else if (current->n > number)
	{
		new->next = current;
		*head = new;
	} else
	{
		while (current->n < number)
		{
			prev = current;
			current = current->next;
			if (current->next == NULL)
				break;
		}
		if (current->n < number)
		{
			current->next = new;
			new->next = NULL;
		}
		else
		{
			prev->next = new;
			new->next = current;
		}
	}
	return (new);
}
