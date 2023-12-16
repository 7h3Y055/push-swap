/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:26:16 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/11 10:06:16 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *j;
	*j = *i;
	*i = tmp;
}

int	from_where(t_stack *a)
{
	t_stack	*a2;

	a2 = get_last(a);
	while (a && a2)
	{
		if (get_max(a) == a->n)
			return (1);
		if (get_max(a) == a2->n)
			return (0);
		a = a->next;
		a2 = a2->prev;
	}
	return (-1);
}
