#include "binary_trees.h"

/**
 * node_height_2 - This function computes the height of a binary tree's node.
 * @tree: the pointer to root node of the tree to measure the height.
 * @n: the accumulated height
 * @height: the pointer to maximum height in the node's tree.
 *
 * Return: void
 */
void node_height_2(const binary_tree_t *tree, size_t n, size_t *height)
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
			node_height_2(tree->left, n + 1, height);
			node_height_2(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: the pointer to root node of the tree to measure the height.
 *
 * Return: Height of tree. If tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	node_height_2(tree, 0, &height);
	return (height);
}
