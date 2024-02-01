#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double the pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * If the address stored in tree is NULL, the created node must become
 * the root node.
 * If the value is already present in the tree, it must be ignored.
 *
 * Return: the pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_nd = NULL;
	bst_t *curr = NULL;

	if (!tree) /* check to make sure that the tree exists. */
		return (NULL);
	new_nd = binary_tree_node(NULL, value); /* create new node */
	if (!new_nd)
		return (NULL);
	if (!*tree) /* check to see if the tree is empty. */
	{
		*tree = new_nd; /* If it is, the new node is assigned to the tree */
		return (new_nd); /* return the new node */
	}
	curr = *tree; /* set the curr node to the root of the tree */
	while (curr)
	{
		if (value < curr->n) /* If new node val is less than curr node val, */
		{
			if (!curr->left)
			{
				curr->left = new_nd;
				new_nd->parent = curr;
				break;
			}
			curr = curr->left; /* new node is inserted to left of curr node. */
		}
		else if (value > curr->n)
		{
			if (!curr->right)
			{
				curr->right = new_nd;
				new_nd->parent = curr;
				break;
			}
			curr = curr->right; /* new node is inserted to right of curr. */
		}
		else
		{
			free(new_nd); /* If new node value is equal to the curr node value. */
			return (NULL);
		}
	}
	return (new_nd); /* return new node */
}
