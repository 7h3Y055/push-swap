/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:42:51 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/05 11:38:48 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol_helper(char const *str, int *i, \
		int *is_negative, int *sign);

long	ft_atol(const char *str)
{
	int		i;
	int		tmp_i;
	long	integer;
	int		sign;
	int		is_negative;

	if (!str)
		return (0);
	i = 0;
	integer = 0;
	sign = 0;
	is_negative = 0;
	if (ft_atol_helper(str, &i, &is_negative, &sign))
		return (2147483650);
	if (sign > 1)
		return (2147483650);
	tmp_i = i;
	while (str[i] >= '0' && str[i] <= '9')
		integer = (integer * 10) + (str[i++] - 48);
	if (tmp_i == i)
		return (2147483650);
	if (is_negative == 1)
		return (-integer);
	return (integer);
}

static int	ft_atol_helper(char const *str, int *i, int *is_negative, int *sign)
{
	int	tmp_i;

	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		*i += 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*is_negative += 1;
		*sign += 1;
		*i += 1;
	}
	tmp_i = *i;
	while (str[tmp_i] >= '0' && str[tmp_i] <= '9')
		tmp_i += 1;
	while ((str[tmp_i] >= 9 && str[tmp_i] <= 13) || str[tmp_i] == ' ')
		tmp_i += 1;
	if (ft_strlen(str + tmp_i) > 0)
		return (1);
	return (0);
}
