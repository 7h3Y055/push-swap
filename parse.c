/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:54:32 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/14 09:01:39 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	parse(int argc, char ***argv)
{
	if (argc == 2)
		*argv = ft_split((*argv)[1], ' ');
	else
		*argv = *argv + 1;
	if (check_arg(*argv))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}
