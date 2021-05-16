#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*Basic Binary Tree*/
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;

};

typedef struct binary_tree_s binary_tree_t;

/*Basic Binary Tree*/
typedef struct binary_tree_s heap_t;

/*Mandatory Task Functions*/
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
size_t binary_tree_size(const binary_tree_t *tree);
int heap_extract(heap_t **root);

/*Functions printing*/
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
