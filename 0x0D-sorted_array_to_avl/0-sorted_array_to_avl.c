#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/*
avl_t *create_node(int value)
{
	avl_t *node;
	
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	if (!node->n)
	{
		free(node);
		return (NULL);
	}
	return (node); 
}
int find_middle_value(int *array, size_t size)
{
	size_t i;
       	int  max, middle;

	max = array[0];
	middle = 0;
	// printf("finding....\n");
	for (i = 0; i < size; ++i)
	{
		if (max < array[i])
		{
			max = array[i];
		}
        }
	for (i = 0; i < size; ++i)
	{
		if ((max / 2)  >= array[i])
		{
			middle = array[i];
		}
        }
	return (middle);
}
avl_t *add_node(avl_t *node, avl_t *node2){	
	if(node->n > node2->n)
		node->right = node2;
	else
		node->left = node2;
	return (node);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return NULL;

	if (!size)
		return NULL;
	
	size_t i;
	int middle;
	avl_t *node, *node2;

	middle = find_middle_value(array, size);
	node = create_node(middle);

	for (i = 0; i < size; ++i)
	{
		// printf("find: (%03d)", array[i]);
		if (middle != array[i])
		{
			node2 = create_node(array[i]);
			node = add_node(node, node2);
		}
	}
		
	// printf("\n");
	// printf("\n");
	// printf("middle %i\n", middle);
	// printf("tree: \n");
	// binary_tree_print(node);

	return (node);
}
*/

binary_tree_t *add_node(int *array, size_t size, avl_t *parent)
{
	binary_tree_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[(size - 1) / 2];
	node->right = NULL;
	node->left = NULL;
	node->parent = parent;
	
	if (size > 1)
	{
		node->right = add_node(array + (size + 1) / 2, size / 2, node);
		if (node->right == NULL)
			return (NULL);
	}
	if (size > 2)
	{
		node->left = add_node(array, (size - 1) / 2, node);
		if (node->right == NULL)
			return (NULL);
	}

	return (node);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return NULL;

	if (!size)
		return NULL;
		
	return ((avl_t *) add_node(array, size, NULL));
}
