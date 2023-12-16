/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:26:32 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/11 10:36:20 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_stack **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}

void	rra(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}
