#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * count_nodes - count nodes
 * @root: double pointer 
 *
 * Return: number of nodes
 */
int count_nodes(heap_t *root)
{
	int n;

	if (root == NULL)
		return (0);
	if (root)
		n = 1;
	n += count_nodes(root->left);
	n += count_nodes(root->right);

	return (n);
}

/**
 * is_perfect - function that checks if a tree is perfect
 * @tree: pointer
 * Return: 1 if true or 0 if false
 */

int is_perfect(const heap_t *tree)
{
	int p1, p2;

	if (tree == NULL)
		return (0);
	p1 = count_nodes(tree->left);
	p2 = count_nodes(tree->right);
	if (p1 == p2)
		return (1);
	return (0);
}

/**
 * find_parent - find the parent
 * @root: double pointer
 *
 * Return: a pointer
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *p;
	int l, r, lf, rf;

	if (root == NULL)
		return (NULL);

	p = root;
	l = count_nodes(p->left);
	r = count_nodes(p->right);
	lf = is_perfect(p->left);
	rf = is_perfect(p->right);

	if (!l || !r)
		return (p);
	if (!lf || (lf && rf && l == r))
		return (find_parent(p->left));
	else if (!rf || (lf && rf && l > r))
		return (find_parent(p->right));
	return (p);
}

/**
 * sort_nodes - sort a child and a parent node
 * @new: inserted node
 *
 * Return: nothing
 */
void sort_nodes(heap_t **new)
{
	heap_t *current;
	int aux;

	current = *new;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			aux = current->parent->n;
			current->parent->n = current->n;
			current->n = aux;
			*new = current->parent;
		}
		current = current->parent;
	}
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	parent = find_parent(*root);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent == NULL)
		*root = new;
	else if (!(parent->left))
		parent->left = new;
	else
		parent->right = new;
	sort_nodes(&new);
	return (new);
}
