#include "binary_trees.h"

/**
 * tree_stats - This function computes some statistics about a binary tree.
 * @tree: the pointer to root node of the tree to check.
 * @n: the accumulated heightof the curr path in the tree.
 * @leaves: the pointer to tree's leaf count value.
 * @height: the pointer to tree's maximum height value.
 *
 * Return: void
 */
void tree_stats(const binary_tree_t *tree, size_t n,
	size_t *leaves, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (leaves != NULL)
				(*leaves)++;
			if ((height != NULL) && (n > *height))
				*height = n;
		}
		else
		{
			tree_stats(tree->left, n + 1, leaves, height);
			tree_stats(tree->right, n + 1, leaves, height);
		}
	}
}

/**
 * binary_tree_is_perfect - This function checks if a binary tree is perfect.
 * @tree: the pointer to root node of the tree to check.
 *
 * Return: 1 if tree is full. 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves_count = 0;
	size_t tree_height = 0;

	tree_stats(tree, 0, &leaves_count, &tree_height);
	return ((int)leaves_count == (1 << tree_height) ? 1 : 0);
}
