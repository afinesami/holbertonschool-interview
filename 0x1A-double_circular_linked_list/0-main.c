#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
	List *tmp;

	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
		printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
		tmp = tmp->next;
		if (tmp == list)
			break;
	}
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	List *list;

	list = NULL;
	add_node_end(&list, "Holberton");
	add_node_end(&list, "School");
	add_node_end(&list, "Full");
	add_node_end(&list, "Stack");
	add_node_end(&list, "Engineer");

	printf("Added to the end:\n");
	print_list(list);
	list = NULL;
	add_node_begin(&list, "Holberton");
	add_node_begin(&list, "School");
	add_node_begin(&list, "Full");
	add_node_begin(&list, "Stack");
	add_node_begin(&list, "Engineer");

	printf("Added to the beginning:\n");
	print_list(list);
	return (0);
}
