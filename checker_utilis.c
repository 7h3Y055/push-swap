/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   checker_utilis.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouchma <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/12/14 09:03:00 by ybouchma		  #+#	#+#			 */
/*   Updated: 2023/12/14 11:27:17 by ybouchma		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "checker.h"

int	check_arg(char **argv)
{
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (1);
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (i != j && ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parse(int argc, char ***argv)
{
	int	i;

	i = 0;
	if (argc == 2)
		*argv = ft_split((*argv)[1], ' ');
	else
		*argv = *argv + 1;
	if (check_arg(*argv))
	{
		ft_putendl_fd("Error", 2);
		if (argc == 2)
		{
			while ((*argv)[i])
				free((*argv)[i++]);
			free(*argv);
		}
		exit(1);
	}
}

void	free_stacks(t_stack *a, t_stack *b)
{
	void	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}

int	valid_cmd(char *cmd)
{
	char	*cmds[12];
	int		i;

	cmds[0] = "sa\n";
	cmds[1] = "sb\n";
	cmds[2] = "ss\n";
	cmds[3] = "pa\n";
	cmds[4] = "pb\n";
	cmds[5] = "ra\n";
	cmds[6] = "rb\n";
	cmds[7] = "rr\n";
	cmds[8] = "rra\n";
	cmds[9] = "rrb\n";
	cmds[10] = "rrr\n";
	cmds[11] = NULL;
	i = 0;
	while (cmds[i])
	{
		if (ft_strncmp(cmds[i], cmd, 5) == 0)
			return (0);
		i++;
	}
	return (1);
}
