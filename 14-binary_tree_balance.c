#include "binary_trees.h"

/**
 * node_height - This function computes the height of a binary tree's node.
 * @tree: the pointer to root node of the tree to measure the height.
 * @n: the accumulated height
 * @height: the pointer to maximum height in the node's tree.
 *
 * Return: void
 */
void node_height(const binary_tree_t *tree, int n, int *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			node_height(tree->left, n + 1, height);
			node_height(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_balance - This function measures the balance factor of,
 * a binary tree.
 * @tree: the pointer to root node of the tree to measure the balance factor.
 *
 * Return: balance factor of a binary tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int bal_fctr = 0, ht_lft = 0, ht_rght = 0;

	if (tree == NULL)
		return (0);

	node_height(tree->left, 1, &ht_lft);
	node_height(tree->right, 1, &ht_rght);

	bal_fctr = ht_lft - ht_rght;
	return (bal_fctr);
}
