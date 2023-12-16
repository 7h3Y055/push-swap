/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:45:35 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/05 11:37:33 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int n, t_stack *prev)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = prev;
	return (node);
}

void	add_back(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	tmp = *head;
	if (!tmp)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_stack	*get_last(t_stack *head)
{
	t_stack	*tmp;

	if (!head)
		return (NULL);
	while (head)
	{
		tmp = head;
		head = head->next;
	}
	return (tmp);
}

int	is_sorted(t_stack *head)
{
	int	n;
	int	sorted;

	if (!head)
		return (-1);
	sorted = 1;
	n = head->n;
	head = head->next;
	while (head && sorted)
	{
		if (head->n < n)
			sorted = 0;
		n = head->n;
		head = head->next;
	}
	return (sorted);
}

int	get_max(t_stack *head)
{
	int	tmp;

	if (!head)
		return (INT_MIN);
	tmp = head->n;
	head = head->next;
	while (head)
	{
		if (head->n > tmp)
			tmp = head->n;
		head = head->next;
	}
	return (tmp);
}
