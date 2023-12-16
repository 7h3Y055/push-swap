/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:40:26 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/16 12:17:12 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap(const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	while (argv[i])
		add_back(&a, new_node(ft_atol(argv[i++]), get_last(a)));
	if (is_sorted(a) == 1)
		return (a);
	else if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		tiny(&a);
	else if (stack_len(a) == 4)
		sort_4(&a, &b);
	else if (stack_len(a) == 5)
		sort_5(&a, &b);
	else if (stack_len(a) > 5)
		sort_big_stack(&a, &b);
	return (a);
}
