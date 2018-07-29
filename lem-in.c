/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:06:14 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:08:05 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_init(t_var **var)
{
	t_var		*temp;

	if (!(temp = (t_var*)malloc(sizeof(t_var))))
		return (0);
	temp->rooms = NULL;
	temp->moves = NULL;
	temp->txt = NULL;
	temp->ants = 0;
	temp->comand = 0;
	temp->error = 0;
	temp->start_count = 0;
	temp->end_count = 0;
	temp->grup_valid = 0;
	temp->bon.count_line = 0;
	temp->bon.error_key = 0;
	temp->bon.error_line = 0;
	temp->bon.way = 0;
	temp->bon.count_iter = 0;
	*var = temp;
	return (1);
}

static int		add_way(t_rooms *room, t_way **way)
{
	t_way		*tway;
	int			count;

	count = 0;
	tway = NULL;
	while (room->start != 4)
		room = room->next;
	if (!room->prev)
		return (0);
	while (room)
	{
		ft_newlist_way(&tway, room);
		if (room->start)
			room->stat = room->start;
		else
			room->stat = 5;
		room = room->prev;
		count++;
	}
	tway->distance = count;
	if (*way)
		tway->next_way = *way;
	*way = tway;
	return (1);
}

static void		reset_stat_room(t_rooms *rooms)
{
	while (rooms)
	{
		rooms->prev = NULL;
		rooms->lenmove = 2147483647;
		if (rooms->stat < 3)
			rooms->stat = 0;
		rooms = rooms->next;
	}
}

static void		write_txt(t_txt *txt)
{
	t_txt *temp;

	while (txt)
	{
		temp = txt->next;
		ft_printf("%s\n", txt->string);
		free(txt->string);
		txt->string = NULL;
		free(txt);
		txt = temp;
	}
	temp = NULL;
	txt = NULL;
	ft_printf("\n");
}

int				main(int argc, char **argv)
{
	t_var		*var;
	t_way		*way;

	way = NULL;
	ft_init(&var);
	if (argc != 1)
		ft_bonus(var, argc, argv);
	read_instruction(var);
	validate_instruction(var);
	while (algorithm(var))
	{
		add_way(var->rooms, &way);
		reset_stat_room(var->rooms);
	}
	if (!way)
	{
		var->error = -18;
		ft_errors(var);
	}
	write_txt(var->txt);
	ants_move(var->ants, way, var->bon.count_iter);
	ft_free_way(way, var);
	//system("leaks lem-in");
}
