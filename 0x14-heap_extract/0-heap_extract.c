#include "binary_trees.h"

/**
 * bt_height - Check the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t bt_height(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	h_left = tree->left ? 1 + bt_height(tree->left) : 0;
	h_right = tree->right ? 1 + bt_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * bt_preorder - goes through a binary tree using pre-order traversal
 * @root: pointer root of the tree
 * @node: pointer node in the tree
 * @h: height of tree
 * @l: layer on the tree
 **/
void bt_preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		bt_preorder(root->left, node, h, l);
	if (root->right)
		bt_preorder(root->right, node, h, l);
}

/**
 * bt_sorting - binary tree Heapsort
 * @tmp: pointer to the heap root
 * Return: pointer to last node
 **/

heap_t *bt_sorting(heap_t *tmp)
{
	int aux;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			aux = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = aux;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			aux = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = aux;
			tmp = tmp->right;
		}

	}
	return (tmp);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/

int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);
	tmp = *root;
	value = tmp->n;
	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}
	bt_preorder(tmp, &node, bt_height(tmp), 0);
	tmp = bt_sorting(tmp);
	tmp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
