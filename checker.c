/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:38 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/14 12:16:58 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_cmd_helper(char *cmd, t_stack **a, t_stack **b)
{
	if (ft_strncmp(cmd, "rra\n", 5) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(cmd, "rrr\n", 5) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	apply_cmd(char *cmd, t_stack **a, t_stack **b)
{
	if (ft_strncmp(cmd, "sa\n", 5) == 0)
		swap_stack(a);
	else if (ft_strncmp(cmd, "sb\n", 5) == 0)
		swap_stack(b);
	else if (ft_strncmp(cmd, "ss\n", 5) == 0)
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (ft_strncmp(cmd, "ra\n", 5) == 0)
		rotate(a);
	else if (ft_strncmp(cmd, "rb\n", 5) == 0)
		rotate(b);
	else if (ft_strncmp(cmd, "rr\n", 5) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(cmd, "pa\n", 5) == 0)
		push(a, b);
	else if (ft_strncmp(cmd, "pb\n", 5) == 0)
		push(b, a);
	else
		apply_cmd_helper(cmd, a, b);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*cmd;

	cmd = (char *)1;
	while (cmd)
	{
		cmd = get_next_line(0);
		if (!cmd)
			return ;
		if (valid_cmd(cmd))
		{
			ft_putendl_fd("Error", 2);
			free(cmd);
			free_stacks(*a, *b);
			close(0);
			get_next_line(0);
			exit(1);
		}
		apply_cmd(cmd, a, b);
		free(cmd);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc > 1 && ft_strlen(argv[1]) <= 0))
		return (1);
	parse(argc, (char ***)&argv);
	i = 0;
	while (argv[i])
		add_back(&a, new_node(ft_atol(argv[i++]), get_last(a)));
	i = 0;
	if (argc <= 2)
	{
		while (argv[i])
			free((char *)argv[i++]);
		free(argv);
	}
	checker(&a, &b);
	if (!b && a && is_sorted(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (free_stacks(a, b), 0);
}
