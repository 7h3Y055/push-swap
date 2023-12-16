/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:02:39 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/14 09:01:34 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const **argv)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	tmp = NULL;
	if (argc < 2 || (argc > 1 && ft_strlen(argv[1]) <= 0))
		return (1);
	if (!parse(argc, (char ***)&argv))
		tmp = push_swap(argv);
	i = 0;
	if (argc <= 2)
	{
		while (argv[i])
			free((char *)argv[i++]);
		free(argv);
	}
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	return (0);
}
