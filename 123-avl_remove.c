
#include "binary_trees.h"

avl_t *inorder_successor(avl_t *node);
avl_t *avl_rebalance(avl_t *node);

/**
 * avl_remove - removes a node from an AVL tree
 * @root: the pointer to root node of the tree for removing a node
 * @value: the value to remove in the tree
 * Return: the pointer to root node of the tree after removing the
 * desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tempo = NULL, *successor = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			tempo = root->left ? root->left : root->right;
			if (tempo)
				tempo->parent = root->parent;
			free(root);
			return (avl_rebalance(tempo));
		}
		else
		{
			successor = inorder_successor(root->right);
			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
	}
	return (avl_rebalance(root));
}

/**
 * inorder_successor - finds the inorder successor of a node
 * @node: the pointer to node
 * Return: the pointer to inorder successor node
 */
avl_t *inorder_successor(avl_t *node)
{
	avl_t *curr = node;

	while (curr && curr->left)
		curr = curr->left;
	return (curr);
}

/**
 * avl_rebalance - rebalances an AVL tree
 * @node: the pointer to node to rebalance
 * Return: the pointer to root node of the tree after rebalancing
 */
avl_t *avl_rebalance(avl_t *node)
{
	int balance_factor;

	if (!node)
		return (NULL);
	balance_factor = binary_tree_balance(node);
	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}
