
#include "binary_trees.h"

avl_t *insert(avl_t *tree, avl_t *node);
avl_t *rebalance(avl_t *tree, avl_t *node);

/**
 * avl_insert - Inserts a value in an AVL Tree
 *
 * @tree: Pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_nd = NULL;

	if (!tree)
		return (NULL);

	new_nd = binary_tree_node(NULL, value);
	*tree = insert(*tree, new_nd);
	return (new_nd);
}

/**
 * insert - Inserts a value in an AVL Tree
 * @tree: Pointer to the root node of the AVL tree for inserting the value
 * @node: Node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *insert(avl_t *tree, avl_t *node)
{
	if (!node)
		return (NULL);
	if (!tree)
		return (node);
	if (tree->n > node->n)
	{
		tree->left = insert(tree->left, node);
		tree->left->parent = tree;
	}
	else if (tree->n < node->n)
	{
		tree->right = insert(tree->right, node);
		tree->right->parent = tree;
	}
	else if (tree->n == node->n)
	{
		free(node);
		node = NULL;
		return (tree);
	}

	return (rebalance(tree, node));
}

/**
 * rebalance - rebalances an AVL tree
 * @tree: the pointer to root node of the tree to rebalance
 * @node: the pointer to node to be inserted
 * Return: the pointer to new root node of the tree once rebalanced
 */
avl_t *rebalance(avl_t *tree, avl_t *node)
{
	int bal_fctr;

	if (!tree)
		return (NULL);

	bal_fctr = binary_tree_balance(tree);

	if (bal_fctr > 1)
	{
		/* left-right case */
		if (tree->left->n < node->n)
			tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (bal_fctr < -1)
	{
		/* right-left case */
		if (tree->right->n > node->n)
			tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}
