#include "deck.h"
#include <string.h>
#include <stdlib.h>

/**
 * sort_value - Sort the deck by value
 * @deck: deck to sort
 */
void sort_value(deck_node_t **deck)
{
	deck_node_t *head = *deck;
	int check = 1;

	while (check)
	{
		check = 0;
		while (head->next)
		{
			if (check_value(head->card->value) >
				check_value(head->next->card->value))
			{
				swap(head->next, 0);
				if (!head->prev->prev)
					*deck = head->prev;
				check = 1;
			}
			else
				head = head->next;
		}
		if (check == 0)
			return;
		while (head->prev)
		{
			if (check_value(head->card->value) <
				check_value(head->prev->card->value))
			{
				swap(head->prev, 1);
				if (!head->prev)
					*deck = head;
				check = 1;
			}
			else
				head = head->prev;
		}
	}
}

/**
 * sort_kind - Sort the deck by kind
 * @deck: deck to sort
 */
void sort_kind(deck_node_t **deck)
{
	deck_node_t *head = *deck;
	int check = 1;

	while (check)
	{
		check = 0;
		while (head->next)
		{
			if (head->card->kind > head->next->card->kind)
			{
				swap(head->next, 0);
				if (!head->prev->prev)
					*deck = head->prev;
				check = 1;
			}
			else
				head = head->next;
		}
		if (check == 0)
			break;
		while (head->prev)
		{
			if (head->card->kind < head->prev->card->kind)
			{
				swap(head->prev, 1);
				if (!head->prev)
					*deck = head;
				check = 1;
			}
			else
				head = head->prev;
		}
	}
}

/**
 * swap - Swap a node to the right
 * @temp: Node to swap
 * @i: integer
 */
void swap(deck_node_t *temp, int i)
{
	if (i == 0)
	{
		if (temp->next)
			temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		temp->next = temp->prev;
		temp->prev = temp->prev->prev;
		if (temp->prev)
			temp->prev->next = temp;
		temp->next->prev = temp;
	}
	else
	{
		if (temp->prev)
			temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->prev = temp->next;
		temp->next = temp->next->next;
		if (temp->next)
			temp->next->prev = temp;
		temp->prev->next = temp;
	}
}

/**
 * check_value - check the value of the card
 * @string: string to check
 * Return: the numerical value
 */
int check_value(const char *string)
{
	if (strcmp("Ace", string) == 0)
		return (1);
	if (strcmp("Jack", string) == 0)
		return (11);
	if (strcmp("Queen", string) == 0)
		return (12);
	if (strcmp("King", string) == 0)
		return (13);
	return (atoi(string));
}

/**
 * sort_deck - sort the deck
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !*deck || !(*deck)->next)
		return;
	sort_value(deck);
	sort_kind(deck);
}
