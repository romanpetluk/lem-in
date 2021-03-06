/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:43:09 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/29 12:43:11 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*ft_errors_def(int errors)
{
	char	*temp;

	temp = NULL;
	if (errors == -1)
		temp = ERROR_ANTS;
	else if (errors == -2)
		temp = ERROR_L;
	else if (errors == -3)
		temp = ERROR_LINE;
	else if (errors == -4)
		temp = ERROR_MINUS;
	else if (errors == -5)
		temp = ERROR_ROOM_ARG;
	else if (errors == -6)
		temp = ERROR_COORD1;
	else if (errors == -7)
		temp = ERROR_COORD2;
	else if (errors == -8)
		temp = ERROR_ROOM_NAME;
	else if (errors == -9)
		temp = ERROR_DUP_START;
	else if (errors == -10)
		temp = ERROR_DUP_END;
	return (temp);
}

static char	*ft_errors_def2(int errors)
{
	char	*temp;

	temp = NULL;
	if (errors == -11)
		temp = ERROR_COM_ROOM;
	else if (errors == -12)
		temp = ERROR_NUMB_ANTS;
	else if (errors == -13)
		temp = ERROR_COM_LINK;
	else if (errors == -14)
		temp = ERROR_LINK_ARG;
	else if (errors == -15)
		temp = ERROR_LINK_FAIL;
	else if (errors == -16)
		temp = ERROR_NOT_START;
	else if (errors == -17)
		temp = ERROR_NOT_END;
	else if (errors == -18)
		temp = ERROR_NOT_S_E;
	return (temp);
}

void		ft_errors(t_var *var)
{
	char	*s;

	s = NULL;
	if (var->error && var->bon.error_key == 0)
		ft_printf("ERROR\n");
	else
	{
		if (var->error > -11)
			s = ft_errors_def(var->error);
		else
			s = ft_errors_def2(var->error);
		ft_printf(KRED "ERROR");
		ft_printf(KWHT " : ");
		if (var->bon.error_line)
			ft_printf("line - %d\n", var->bon.count_line);
		ft_printf("%s\n", s);
	}
	ft_free_all(var);
	exit(0);
}
