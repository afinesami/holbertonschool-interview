#include "binary_trees.h"
/**
 * preorder_max_min - goes through a binary tree using pre-order traversal
 * @value: value[0] max value, value[1] min value
 * @tree: pointer to the root
 * Return: no return
 **/
void preorder_max_min(const binary_tree_t *tree, int *value)
{
	if (!tree)
		return;
	if (value[0] < tree->n)
		value[0] = tree->n;
	if (value[1] > tree->n)
		value[1] = tree->n;
	if (tree->left)
		preorder_max_min(tree->left, value);
	if (tree->right)
		preorder_max_min(tree->right, value);
}
/**
 * binary_tree_is_bst - checks if a binary tree is bts
 * @tree: pointer to the node
 * Return: 1 if it is bts 0 otherwise
 **/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int value[2], tmp1, tmp2;

	if (!tree)
		return (0);

	if (tree->left)
		tmp1 = (binary_tree_is_bst(tree->left));
	if (tree->right)
		tmp2 = (binary_tree_is_bst(tree->right));
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		value[0] = tree->left->n;
		value[1] = value[0];
		preorder_max_min(tree->left, &value[0]);
		if (value[0] >= tree->n)
			return (0);
	}
	if (tree->right)
	{
		value[0] = tree->right->n;
		value[1] = value[0];
		preorder_max_min(tree->right, &value[0]);
		if (value[1] <= tree->n)
			return (0);
	}
	return (tmp1 && tmp2);
}
