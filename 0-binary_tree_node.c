#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a binary tree.
 *
 * @parent: the pointer to the node of the parent node
 * @value: the value of the new node
 *
 * When created, a node does not have any child.
 *
 * Return: pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nd = NULL;

	new_nd = malloc(sizeof(binary_tree_t));
	if (new_nd != NULL)
	{
		new_nd->left = NULL;
		new_nd->right = NULL;
		new_nd->parent = parent;
		new_nd->n = value;
	}
	return (new_nd);
}
