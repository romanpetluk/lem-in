/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:13:25 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:14:24 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_atoi_lem(char *str, int n, int i)
{
	long	re;

	if (str)
	{
		re = 0;
		if (str[i] == '-')
			n = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			re *= 10;
			re += ((str[i++] - 48) * n);
			if (re > 2147483647 || re < -2147483648)
				return (-1);
		}
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != '#')
			return (-1);
		return ((int)(re));
	}
	return (-1);
}

int			read_instruction_ants(char *s, t_var *var)
{
	var->ants = ft_atoi_lem(s, 1, 0);
	if (var->ants < 0)
	{
		return (var->error = -1);
	}
	var->grup_valid++;
	return (1);
}
