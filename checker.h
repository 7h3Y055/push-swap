/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:42:04 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/14 12:16:53 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				n;
	int				i;
	struct s_stack	*prev;
	struct s_stack	*next;	
}	t_stack;

void	checker(t_stack **a, t_stack **b);
void	parse(int argc, char ***argv);
int		is_sorted(t_stack *head);
void	swap_stack(t_stack **head);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	add_back(t_stack **head, t_stack *new_node);
t_stack	*new_node(int n, t_stack *prev);
long	ft_atol(const char *str);
t_stack	*get_last(t_stack *head);
void	free_stacks(t_stack *a, t_stack *b);
int		valid_cmd(char *cmd);

#endif
