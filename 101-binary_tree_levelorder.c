#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

q_node *enqueue(binary_tree_t *node, q_node **tail);
void dequeue(q_node **head);

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 *
 * Description: Level-order traversal is also known as breadth-first traversal.
 * This function uses a queue to traverse the tree. The queue is implemented
 * using a linked list. Time complexity is O(n) where n is the number of nodes.
 * Space complexity is O(n) where n is the number of nodes.
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	q_node *head = NULL, *tail = NULL, *current = NULL;
	binary_tree_t *b_tree_node = NULL;

	if (!tree || !func)
		return;
	head = enqueue((binary_tree_t *)tree, &tail);
	current = head;
	while (current)
	{
		b_tree_node = current->b_tree_node;
		func(b_tree_node->n);
		if (b_tree_node->left)
			enqueue(b_tree_node->left, &tail);
		if (b_tree_node->right)
			enqueue(b_tree_node->right, &tail);
		dequeue(&head);
		current = head;
	}
}

/**
 * enqueue - add a node to the end of a queue
 * @node: pointer to the binary tree node to add to the queue
 * @tail: pointer to the tail of the queue
 * Return: pointer to the new node
 */
q_node *enqueue(binary_tree_t *node, q_node **tail)
{
	q_node *new_node = NULL;

	if (!node)
		return (NULL);

	new_node = malloc(sizeof(q_node));
	if (!new_node)
		return (NULL);

	new_node->b_tree_node = node;
	new_node->next = NULL;
	if (tail && *tail)
		(*tail)->next = new_node;
	*tail = new_node;
	return (new_node);
}

/**
 * dequeue - remove a node from the front of a queue
 * @head: pointer to the head of the queue
 * Return: void
 */
void dequeue(q_node **head)
{
	q_node *temp = NULL;

	if (!head || !*head)
		return;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
