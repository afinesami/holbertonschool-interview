#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
/**
 * binary_tree_insert_right - inserts a node in the binary tree (right)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node inserted
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->right;
	node = binary_tree_node(parent, value);
	parent->right = node;
	if (tmp != NULL)
	{
		node->right = tmp;
		tmp->parent = node;
	}
	return (node);
}
/**
 * binary_tree_insert_left - inserts a node in the binary tree (left)
 * @parent: pointer to a parent node
 * @value: number value in the node inserted
 * Return: pointer to the new node
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->left;
	node = binary_tree_node(parent, value);
	parent->left = node;
	if (tmp != NULL)
	{
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}
/**
 * height - mesures height
 * @tree: pointer to the node
 * Return: height
 **/
int height(binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = height(tree->right) + 1;
	left = height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect (complete&BF=1)
 * @tree: pointer to the node
 * Return: 1 if it is perfect 0 otherwise
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left && !tree->right) || ((binary_tree_is_perfect(tree->left)
					== 1 && binary_tree_is_perfect(tree->right) == 1) && height(tree->left)
				== height(tree->right)))
		return (1);
	return (0);
}
