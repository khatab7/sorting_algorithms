#include "sort.h"

/**
 * swap_listint_left - Swaps node of doubly linked list with its previous
 * @head: Adress to head of linked list
 * @node: Node to swap
 * Return: Adress to head of linked list
 */
listint_t	**swap_listint_left(listint_t **head, listint_t *node)
{
	listint_t	*tmp, *node_left;

	if (!head || !*head || !node)
		return (NULL);
	if (node->prev == *head)
		*head = node;
	tmp = node->next;
	node_left = node->prev;
	if (node->prev->prev)
		node->prev->prev->next = node;
	if (node->next)
		node->next->prev = node->prev;
	node->next = node->prev;
	node->prev = node->prev->prev;
	node_left->prev = node;
	node_left->next = tmp;
	print_list(*head);
	return (head);
}

/**
 * insertion_sort_list - Sorts doubly linked list using Insertion Sort
 * @list: Adress to head of linked list
 */
void	insertion_sort_list(listint_t **list)
{
	listint_t *iter_a, *iter_b;

	if (!list || !*list || !(*list)->next)
		return;
	iter_a = *list;
	while (iter_a)
	{
		iter_b = iter_a;
		while (iter_b && iter_b->prev && iter_b->n < iter_b->prev->n)
			swap_listint_left(list, iter_b);
		iter_a = iter_a->next;
	}
}
