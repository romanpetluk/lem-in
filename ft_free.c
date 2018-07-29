/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:25:53 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/29 12:25:54 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_free_txt(t_txt *txt)
{
	t_txt	*temp;

	while (txt)
	{
		temp = txt->next;
		free(txt->string);
		txt->string = NULL;
		free(txt);
		txt = temp;
	}
	temp = NULL;
	txt = NULL;
}

static void	ft_free_room_move(t_var *var)
{
	t_move	*tmoov;
	t_rooms	*troom;

	if (var->moves)
	{
		while (var->moves)
		{
			tmoov = var->moves->next;
			var->moves->name_next = NULL;
			var->moves->name = NULL;
			free(var->moves);
			var->moves = tmoov;
		}
	}
	if (var->rooms)
	{
		while (var->rooms)
		{
			free(var->rooms->name);
			troom = var->rooms->next;
			free(var->rooms);
			var->rooms = troom;
		}
	}
	free(var);
}

void		ft_free_all(t_var *var)
{
	ft_free_txt(var->txt);
	ft_free_room_move(var);
}

void		ft_free_way(t_way *way, t_var *var)
{
	t_way	*tway;
	t_way	*temp;

	if (var->bon.way)
		way_list(way);
	while (way)
	{
		tway = way;
		way = way->next_way;
		while (tway)
		{
			temp = tway->next_room;
			free(tway);
			tway = temp;
		}
	}
	ft_free_room_move(var);
}
