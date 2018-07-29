/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:58:47 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:01:14 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		find_start(t_rooms *troom, t_rooms **start)
{
	while (troom)
	{
		if (troom->stat == 3)
		{
			troom->lenmove = 0;
			*start = troom;
			return (0);
		}
		troom = troom->next;
	}
	return (1);
}

//void find_move2(t_rooms *rooms,t_rooms *start, t_move *move)
//{
//
//}

static void		find_move(t_rooms *rooms, t_rooms *start, t_move *move)
{
	t_rooms		*troom;

	while (move)
	{
		troom = rooms;
		if (move->name == start->name)
		{
			while (troom && troom->name != move->name_next)
				troom = troom->next;
			if (troom->lenmove > (move->distance + start->lenmove))
			{
				troom->lenmove = (move->distance + start->lenmove);
				troom->prev = start;
				if (troom->stat < 4)
					troom->stat = 1;
			}
		}
		else if (move->name_next == start->name)
		{
			while (troom && troom->name != move->name)
				troom = troom->next;
			if (troom->lenmove > move->distance + start->lenmove)
			{
				troom->lenmove = (move->distance + start->lenmove);
				troom->prev = start;
				if (troom->stat < 4)
					troom->stat = 1;
			}
		}
		move = move->next;
	}
}

//static void		find_move(t_rooms *rooms, t_rooms *start, t_move *move)
//{
//	t_rooms		*troom;
//
//	while (move)
//	{
//		troom = rooms;
//		if (move->name == start->name)
//		{
//			while (troom && troom->name != move->name_next)
//				troom = troom->next;
//			if (troom->lenmove > (move->distance + start->lenmove))
//			{
//				troom->lenmove = (move->distance + start->lenmove);
//				troom->prev = start;
//				if (troom->stat < 4)
//					troom->stat = 1;
//			}
//		}
//		else if (move->name_next == start->name)
//		{
//			while (troom && troom->name != move->name)
//				troom = troom->next;
//			if (troom->lenmove > move->distance + start->lenmove)
//			{
//				troom->lenmove = (move->distance + start->lenmove);
//				troom->prev = start;
//				if (troom->stat < 4)
//					troom->stat = 1;
//			}
//		}
//		move = move->next;
//	}
//}

static int		find_l(t_rooms *rooms, t_rooms **room_l)
{
	t_rooms		*l;
	t_rooms		*troom;

	troom = rooms;
	l = NULL;
	while (troom)
	{
		if (troom->stat == 1)
		{
			if (!l)
				l = troom;
			else if (troom->lenmove < l->lenmove)
				l = troom;
		}
		troom = troom->next;
	}
	if (l == NULL)
		if (find_start(rooms, &l))
			return (0);
	l->stat = 2;
	*room_l = l;
	return (1);
}

int				algorithm(t_var *var)
{
	t_rooms		*room_l;
	t_rooms		*temp;

	temp = var->rooms;
	while (find_l(temp, &room_l))
	{
		find_move(temp, room_l, var->moves);
	}
	while (temp->start != 4)
		temp = temp->next;
	if (temp->prev)
	{
		if (temp->prev->start == 3)
		{
			remove_start_finish(temp, &var->moves);
		}
		return (1);
	}
	return (0);
}
