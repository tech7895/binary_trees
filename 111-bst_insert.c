#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double the pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: the pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_nd, *curr;

	if (!tree)
		return (NULL);

	new_nd = binary_tree_node(NULL, value);
	if (!new_nd)
		return (NULL);

	if (!*tree)
		return (*tree = new_nd);

	curr = *tree;

	while (curr)
	{
		if (value < curr->n)
		{
			if (!curr->left)
				return (curr->left = new_nd), new_nd->parent = curr, new_nd;
			curr = curr->left;
		}
		else if (value > curr->n)
		{
			if (!curr->right)
				return (curr->right = new_nd), new_nd->parent = curr, new_nd;
			curr = curr->right;
		}
		else
		{
			free(new_nd);
			return (NULL);
		}
	}

	return (new_nd);
}
