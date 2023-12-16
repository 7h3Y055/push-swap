/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:26:39 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/16 12:16:20 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny(t_stack **a)
{
	if (get_max(*a) == (*a)->n && !is_sorted(*a))
		sa(a);
	if (get_max(*a) == (*a)->next->n && !is_sorted(*a))
		rra(a);
	if ((*a)->n > (*a)->next->n && !is_sorted(*a))
		sa(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*a_tmp;
	int		min;

	while (stack_len(*a) > 3)
	{
		a_tmp = *a;
		min = a_tmp->n;
		while (a_tmp)
		{
			if (min > a_tmp->n)
				min = a_tmp->n;
			a_tmp = a_tmp->next;
		}
		while (min != (*a)->n)
			ra(a);
		pb(b, a);
	}
	tiny(a);
	while (*b)
		pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	*tab;

	tab = NULL;
	tab = create_sort(tab, *a, stack_len(*a));
	if (!tab)
		return ;
	index_stack(*a, tab, stack_len(*a));
	while (stack_len(*a) > 3)
	{
		if ((*a)->i == 0 || (*a)->i == 4)
			pb(b, a);
		else
			ra(a);
	}
	tiny(a);
	while (*b)
	{
		pa(a, b);
		if ((*a)->i != 0)
			ra(a);
	}
	free((void *)tab);
}

void	sort_big_stack(t_stack **a, t_stack **b)
{
	int	*tab;

	tab = NULL;
	tab = create_sort(tab, *a, stack_len(*a));
	if (!tab)
		return ;
	index_stack(*a, tab, stack_len(*a));
	if (stack_len(*a) <= 100)
		push_a_to_b(a, b, 15);
	else
		push_a_to_b(a, b, 30);
	push_b_to_a(a, b);
	free((void *)tab);
}
