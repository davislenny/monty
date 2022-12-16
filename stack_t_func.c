#include "monty.h"
/**
 * add_dnodeint - adds new_node at the beginning of a list
 * @h: points to head node
 * @n: node int
 * Return: pointer to new node
 */
stack_t *add_dnodeint(stack_t **h, const int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
		return (NULL);
	node->n = n;
	node->prev = NULL;

	if (!*h)
	{
		node->next = NULL;
		*h = node;
	}
	else
	{
		node->next = *h;
		(*h)->prev = node;
		*h = node;
	}
	return (node);
}

/**
 * add_dnodeint_end - adds a node at the end of a list
 * @h: points to head node
 * @n: node integer
 * Return: ponter to the new node
 */
stack_t *add_dnodeint_end(stack_t **h, const int n)
{
	stack_t *temp = *h, *node = malloc(sizeof(stack_t));

	if (!node || !h)
		return (node ? free(node), NULL : NULL);

	node->n = n;
	node->next = NULL;

	if (!*h)
	{
		node->prev = NULL;
		*h = node;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
	return (node);
}

/**
 * delete_dnodeint_at_index - deletes node at index of a list
 * @h: points to head node
 * @idx: index to delete
 * Return: 1 success, -1 failure
 */
int delete_dnodeint_at_index(stack_t **h, unsigned int idx)
{
	stack_t *temp, *node;
	unsigned int i = 0;

	if (!*h || !h)
		return (-1);
	if (!idx)
	{
		temp = *h;
		*h = (*h)->next;
		if (*h)
			(*h)->prev = NULL;
		free(temp);
		return (1);
	}
	temp = *h;
	while (temp)
	{
		if (idx == i)
		{
			node->next = temp->next;
			if (temp->next)
				temp->next->prev = node;
			free(temp);
			return (1);
		}
		node = temp;
		temp = temp->next;
		i++;
	}
	return (-1);
}

/**
 * free_dlistint - frees a list
 * @head: points to the head node
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->prev);
	}
	free(temp);
}
