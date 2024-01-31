#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *nw_rt;

	/* If the tree is empty, return NULL. */
	if (!tree)
		return (NULL);

	/* Set the new root to the left child of the tree. */
	nw_rt = tree->left;

	/* If the new root exists, */
	if (nw_rt)
	{
		/* set the left child of the tree to the right child of the new root */
		tree->left = nw_rt->right;

		/* If the right child of the new root exists, */
		if (nw_rt->right)
			/* set the parent of the right child to the tree. */
			nw_rt->right->parent = tree;

		/* Set the right child of the new root to the tree. */
		nw_rt->right = tree;
		/* Set the parent of the new root to the parent of the tree. */
		nw_rt->parent = tree->parent;
		/* Set the parent of the tree to the new root. */
		tree->parent = nw_rt;
	}
	/* Return the new root */
	return (nw_rt);
}
