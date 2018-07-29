/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:04:08 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:05:41 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_newlist_move(t_move **moves, char *r_name1, char *r_name2)
{
	t_move		*new;
	t_move		*temp;

	temp = *moves;
	if (!(new = (t_move *)malloc(sizeof(t_move))))
		return (-1);
	new->next = NULL;
	new->name = r_name1;
	new->name_next = r_name2;
	new->distance = 1;
	if (*moves)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*moves = new;
	return (1);
}

static int		ft_init_room(char **s, t_rooms **new, int comand)
{
	(*new)->next = NULL;
	(*new)->name = s[0];
	(*new)->x = ft_atoi(s[1]);
	(*new)->y = ft_atoi(s[2]);
	(*new)->stat = comand;
	(*new)->start = comand;
	(*new)->ants = 0;
	(*new)->lenmove = 2147483647;
	(*new)->prev = NULL;
	free(s[1]);
	free(s[2]);
	free(s);
	s = NULL;
	return (0);
}

int				ft_newlist_room(char **s, t_rooms **room, int comand)
{
	t_rooms		*new;
	t_rooms		*temp;

	temp = *room;
	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (-1);
	ft_init_room(s, &new, comand);
	if (*room)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*room = new;
	return (1);
}

int				ft_newlist_way(t_way **way, t_rooms *room)
{
	t_way		*new;
	t_way		*temp;

	temp = *way;
	if (!(new = (t_way *)malloc(sizeof(t_way))))
		return (-1);
	new->room = room;
	new->next_room = NULL;
	new->next_way = NULL;
	new->ant = 0;
	new->distance = 0;
	if (temp)
	{
		while (temp->next_room)
			temp = temp->next_room;
		temp->next_room = new;
	}
	else
		*way = new;
	return (1);
}

int				add_string_txt(char *s, t_txt **txt)
{
	t_txt		*new;
	t_txt		*ttxt;

	ttxt = *txt;
	if (!(new = (t_txt *)malloc(sizeof(t_txt))))
		return (-1);
	new->string = s;
	new->next = NULL;
	if (ttxt)
	{
		while (ttxt->next)
			ttxt = ttxt->next;
		ttxt->next = new;
	}
	else
		*txt = new;
	return (1);
}
