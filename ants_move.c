/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:01:56 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:03:39 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	value_move_way(t_way *way, int ants)
{
	t_way	*tway;
	int		distance;
	int		i;

	i = 0;
	if (!way->next_way)
		return (1);
	tway = way;
	distance = tway->distance;
	while (tway->next_way)
	{
		tway = tway->next_way;
		i++;
	}
	if (way->distance < tway->distance + ants - i)
		return (1);
	return (0);
}

static int	find_way_ants(t_way *way, int ants, int p)
{
	t_way	*tway;
	t_way	*temp;

	temp = way;
	while (way)
	{
		tway = way;
		while (tway->next_room && tway->next_room->room->start != 3)
			tway = tway->next_room;
		if (!tway->next_room || tway->next_room->room->ants == 0)
			return (0);
		if (value_move_way(way, tway->next_room->room->ants))
		{
			tway->ant = (ants - tway->next_room->room->ants);
			tway->next_room->room->ants--;
			if (p)
				ft_printf(" ");
			ft_printf("L%d-%s", (tway->ant), tway->room->name);
			p++;
		}
		way = way->next_way;
	}
	return (1);
}

static int	print_ants(t_way *way, int ants, int p)
{
	t_way	*temp;
	t_way	*tway;

	temp = way;
	while (temp)
	{
		tway = temp;
		while (tway->next_room && tway->next_room->room->start != 3)
		{
			if (tway->next_room->ant)
			{
				tway->ant = tway->next_room->ant;
				tway->next_room->ant = 0;
				if (p++)
					ft_printf(" ");
				ft_printf("L%d-%s", (tway->ant), tway->room->name);
			}
			tway = tway->next_room;
		}
		temp = temp->next_way;
	}
	p += find_way_ants(way, ants, p);
	if (p)
		ft_printf("\n");
	return (p);
}

void		ants_move(int ants, t_way *way, int iter)
{
	t_way	*tway;
	int		count;

	count = 0;
	tway = way;
	while (tway->next_room)
		tway = tway->next_room;
	tway->room->ants = ants;
	while (print_ants(way, ants + 1, 0))
		count++;
	if (iter)
		ft_printf("\ncount iteration: %d\n", count);
}
