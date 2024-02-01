#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: the pointer to the root node of the tree to rotate.
 *
 * Return: the pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *nw_rt;

	/* If the tree is empty, return NULL. */
	if (!tree)
		return (NULL);

	/*
	* If the tree is not empty, create a nw_rt variable and set it to
	* the right child of the tree.
	*/
	nw_rt = tree->right;

	/* If the nw_rt is empty, return the tree. */
	if (!nw_rt)
		return (tree);

	/* Set the right child of the tree to the left child of the nw_rt. */
	tree->right = nw_rt->left;

	/*
	* If the left child of the nw_rt is not empty, set the parent of the
	* left child of the nw_rt to the tree.
	*/
	if (nw_rt->left)
		nw_rt->left->parent = tree;

	/* Set the parent of the nw_rt to the parent of the tree. */
	nw_rt->parent = tree->parent;

	/* Set the left child of the nw_rt to the tree. */
	nw_rt->left = tree;

	/* Set the parent of the tree to the nw_rt. */
	tree->parent = nw_rt;

	/* Return the nw_rt. */
	return (nw_rt);
}
