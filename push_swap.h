/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:26:54 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/16 12:16:49 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				n;
	int				i;
	struct s_stack	*prev;
	struct s_stack	*next;	
}	t_stack;

t_stack	*push_swap(const char **argv);
int		parse(int argc, char ***argv);
t_stack	*new_node(int n, t_stack *prev);
void	add_back(t_stack **head, t_stack *new_node);
t_stack	*get_last(t_stack *head);
int		stack_len(t_stack *head);
int		is_sorted(t_stack *head);
int		get_max(t_stack *head);
long	ft_atol(const char *str);
void	tiny(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	sort_big_stack(t_stack **a, t_stack **b);
void	index_stack(t_stack *a, int *tab, int len);
void	push_b_to_a(t_stack **a, t_stack **b);
void	push_a_to_b(t_stack **a, t_stack **b, int len);
int		*create_sort(int *tab, t_stack *a, int len);
void	ft_swap(int *i, int *j);
int		from_where(t_stack *a);
void	swap_stack(t_stack **head);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
