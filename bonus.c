/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:12:48 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/29 12:12:49 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		way_list(t_way *way)
{
	t_way	*tway;
	int		count;

	count = 0;
	ft_printf("\n");
	while (way)
	{
		tway = way;
		while (tway)
		{
			ft_printf("room: '%s'", tway->room->name);
			tway = tway->next_room;
			if (tway)
				ft_printf(" <- ");
			count++;
		}
		ft_printf("\n");
		ft_printf("distance %d\n", way->distance);
		way = way->next_way;
	}
	ft_printf("\n");
}

static void	cmp_key(t_var *var, char *s)
{
	if (!ft_strcmp(s, "-r"))
		(var)->bon.error_key = 1;
	else if (!ft_strcmp(s, "-l"))
		var->bon.error_line = 1;
	else if (!ft_strcmp(s, "-w"))
		var->bon.way = 1;
	else if (!ft_strcmp(s, "-i"))
		var->bon.count_iter = 1;
	else if (!ft_strcmp(s, "-a"))
	{
		(var)->bon.error_key = 1;
		var->bon.error_line = 1;
		var->bon.way = 1;
		var->bon.count_iter = 1;
	}
}

void		ft_bonus(t_var *var, int argc, char **argv)
{
	int		i;

	i = 1;
	while (argc > i)
	{
		cmp_key(var, argv[i]);
		i++;
	}
}
