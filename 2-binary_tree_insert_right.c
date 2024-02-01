#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the,
 * right-child of another node.
 *
 * @parent: the pointer to node to insert the right-child in.
 * @value: the value to store in the new node.
 *
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 *
 * Return: the new node, or NULL on failure or if parent,
 * is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nd = NULL;

	if (parent != NULL)
	{
		new_nd = malloc(sizeof(binary_tree_t));
		if (new_nd != NULL)
		{
			new_nd->left = NULL;
			new_nd->right = parent->right;
			new_nd->parent = parent;
			new_nd->n = value;
			if (parent->right != NULL)
				parent->right->parent = new_nd;
			parent->right = new_nd;
		}
	}
	return (new_nd);
}
