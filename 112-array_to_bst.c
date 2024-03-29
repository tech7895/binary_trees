#include "binary_trees.h"

/**
 * array_to_bst - This builds a Binary Search Tree from an array.
 * @array: the pointer to first element of the array to be converted.
 * @size: number of element in the array.
 *
 * If a value of the array is already present in the tree, this value must
 * be ignored.
 *
 * Return: the pointer to root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	/* Initialize the root node to NULL. */
	bst_t *root = NULL;
	size_t i;

	/* Check if the array is empty. */
	if (!array)
		return (NULL);

	/* Iterate through the array and insert each element into the BST */
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	/* Return the root node of the binary search tree. */
	return (root);
}
