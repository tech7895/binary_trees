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
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node != NULL)
	{
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = parent;
		new_node->n = value;
	}
	return (new_node);
}
