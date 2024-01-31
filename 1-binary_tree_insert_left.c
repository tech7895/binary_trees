#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as the,
 * left-child of another node.
 *
 * @parent: pointer to the node to insert the left-child in.
 * @value: value to store in the new node.
 *
 * Return: the new node, or NULL on failure or if parent,
 * is NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nd = NULL;

	if (parent != NULL)
	{
		new_nd = malloc(sizeof(binary_tree_t));
		if (new_nd != NULL)
		{
			new_nd->left = parent->left;
			new_nd->right = NULL;
			new_nd->parent = parent;
			new_nd->n = value;
			if (parent->left != NULL)
				parent->left->parent = new_nd;
			parent->left = new_nd;
		}
	}
	return (new_nd);
}
