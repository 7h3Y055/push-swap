/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:26:37 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/05 11:35:28 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *a, int *tab, int len)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (tab[i] == a->n)
			{
				a->i = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (get_max(*b) == (*b)->n)
			pa(a, b);
		else
		{
			if (from_where(*b) == 1)
				rb(b);
			else if (from_where(*b) == 0)
				rrb(b);
		}
	}
}

void	push_a_to_b(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->i <= i && i > 1)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if ((*a)->i <= (i + len))
		{
			pb(b, a);
			i++;
		}
		else if ((*a)->i >= i)
			ra(a);
	}
}

int	*create_sort(int *tab, t_stack *a, int len)
{
	int	i;
	int	j;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	i = 0;
	while (a)
	{
		tab[i++] = a->n;
		a = a->next;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	return (tab);
}
