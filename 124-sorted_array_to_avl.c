#include <stdlib.h>
#include "binary_trees.h"

avl_t *s_array_to_avl(int *arr, int l, int r, avl_t *parent);

/**
 * sorted_array_to_avl - This builds an AVL tree from an array
 * @array: the pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: the pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);
	root = s_array_to_avl(array, 0, size - 1, root);
	return (root);
}

/**
 * s_array_to_avl - This builds an AVL tree from an array
 * Description: This function is a helper function for sorted_array_to_avl
 * It takes advantage of the fact that bst result in ordered arrays
 * when traversed inorder
 * @arr: the pointer to the first element of the array to be converted
 * @l: the left index
 * @r: the right index
 * @parent: the pointer to the parent node
 * Return: the pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *s_array_to_avl(int *arr, int l, int r, avl_t *parent)
{
	int index;
	avl_t *new_nd = NULL;

	if (!arr || l > r)
		return (NULL);
	index = l + (r - l) / 2;
	new_nd = binary_tree_node(parent, arr[index]);

	if (!new_nd)
		return (NULL);
	new_nd->left = s_array_to_avl(arr, l, index - 1, new_nd);
	new_nd->right = s_array_to_avl(arr, index + 1, r, new_nd);
	return (new_nd);
}
