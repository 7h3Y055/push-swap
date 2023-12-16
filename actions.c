/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:49:53 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/16 15:32:31 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **head)
{
	if (!head || !*head || stack_len(*head) < 2)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	if ((*a)->next)
		(*a)->next->prev = (*a);
	(*a)->prev = NULL;
	if (*b)
		(*b)->prev = NULL;
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head) || stack_len(*head) < 2)
		return ;
	tmp = get_last(*head);
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = get_last(*head);
	*head = tmp;
	(*head)->next->prev = *head;
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next || stack_len(*head) < 2)
		return ;
	tmp = get_last(*head);
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev->prev = tmp;
	tmp->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a)
{
	if (!a || !(*a))
		return ;
	ft_printf("sa\n");
	swap_stack(a);
}
