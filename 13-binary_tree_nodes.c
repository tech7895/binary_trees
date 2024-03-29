#include "binary_trees.h"

/**
 * binary_tree_is_leaf - This function checks if a node is a leaf.
 * @node: the pointer to node to check.
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_nodes - This function counts the nodes with at least,
 * 1 child in a binary tree.
 * @tree: the pointer to root tree of the tree to count the no. of nodes.
 *
 * A NULL pointer is not a node.
 *
 * Return: number of nodes. If tree is NULL the function must return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	return (1 + left + right);
}
