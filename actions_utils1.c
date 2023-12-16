/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:26:22 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/05 11:30:32 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}

void	sb(t_stack **b)
{
	ft_printf("sb\n");
	swap_stack(b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap_stack(a);
	swap_stack(b);
}

void	pa(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(a, b);
}

void	pb(t_stack **b, t_stack **a)
{
	ft_printf("pb\n");
	push(b, a);
}
