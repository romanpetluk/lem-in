/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:11:51 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:13:07 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		free_fail(char **split)
{
	int		end_split;

	end_split = 0;
	while (split[end_split] != 0)
	{
		free(split[end_split]);
		end_split++;
	}
	free(split[end_split]);
	free(split);
	split = NULL;
}

void		free_failn(char **split, int count)
{
	int		end_split;

	end_split = count;
	while (split[end_split] != 0)
	{
		free(split[end_split]);
		end_split++;
	}
	free(split[end_split]);
	free(split);
	split = NULL;
}

void		validate_instruction(t_var *var)
{
	if (var->start_count != 1)
		var->error = -16;
	else if (var->end_count != 1)
		var->error = -17;
	if (var->error)
		ft_errors(var);
}
