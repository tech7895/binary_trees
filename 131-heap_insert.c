#include <stdlib.h>
#include "binary_trees.h"

int node_count(const heap_t *tree);
heap_t *ins_max_heap(heap_t *node, heap_t *new_nd, int index,
					 int new_nd_index);
heap_t *bottom_up_heapify(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double the pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int size;
	heap_t *new_nd = NULL;

	if (!root)
		return (NULL);

	new_nd = binary_tree_node(NULL, value);
	if (!new_nd)
		return (NULL);

	size = node_count(*root) + 1;
	*root = ins_max_heap(*root, new_nd, 0, size - 1);

	return (bottom_up_heapify(new_nd));
}

/**
 * node_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes in the tree
 */
int node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * ins_max_heap - Inserts a value into a Max Binary Heap
 * @node: Pointer to the root node of the Heap to insert the value
 * @new_nd: Value to store in the node to be inserted
 * @index: Index of curr node
 * @new_nd_index: Index of new node
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *ins_max_heap(heap_t *node, heap_t *new_nd,
					 int index, int new_nd_index)
{
	if (index > new_nd_index)
		return (NULL);
	if (index == new_nd_index)
		return (new_nd);

	node->left = ins_max_heap(node->left, new_nd,
							  index * 2 + 1, new_nd_index);
	if (node->left)
		node->left->parent = node;

	node->right = ins_max_heap(node->right, new_nd,
							   index * 2 + 2, new_nd_index);
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * bottom_up_heapify - Heapifies a Max Binary Heap bottom-up
 * Description: This function swaps the value of a node with the value of its
 * parent while the value of the node is greater than the value of its parent.
 *
 * @node: Pointer to the root node of the Heap to heapify
 * Return: Pointer to the root node of the Heap
 */
heap_t *bottom_up_heapify(heap_t *node)
{
	heap_t *tempo = node;
	int tempo_n;

	while (tempo->parent && tempo->n > tempo->parent->n)
	{
		tempo_n = tempo->n;
		tempo->n = tempo->parent->n;
		tempo->parent->n = tempo_n;
		tempo = tempo->parent;
	}
	return (tempo);
}
