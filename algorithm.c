
#include "lem-in.h"

int		find_start(t_rooms *troom, t_rooms **start)
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

int		room_status(t_rooms *room, t_move *move)
{
	if (tmove->name == start->name)
	{
		while (troom && troom->name != tmove->name_next)
			troom = troom->next;
		if (troom->lenmove > (tmove->distance + start->lenmove))
		{
			troom->lenmove = (tmove->distance + start->lenmove);
			troom->prev = start;
			if (troom->stat != 4)
				troom->stat = 1;
		}
	}
}

int		find_move(t_rooms *rooms,t_rooms *start, t_move *move)
{
	t_move		*tmove;
	t_rooms		*troom;

	tmove = move;
	while (tmove)
	{
		troom = rooms;
		if (tmove->name == start->name)
		{
			while (troom && troom->name != tmove->name_next)
				troom = troom->next;
			if (troom->lenmove > (tmove->distance + start->lenmove))
			{
				troom->lenmove = (tmove->distance + start->lenmove);
				troom->prev = start;
				if (troom->stat != 4)
					troom->stat = 1;
			}
		}
		else if (tmove->name_next == start->name)
		{
			while (troom && troom->name != tmove->name)
				troom = troom->next;
			if (troom->lenmove > tmove->distance + start->lenmove)
			{
				troom->lenmove = (tmove->distance + start->lenmove);
				troom->prev = start;
				if (troom->stat != 4)
					troom->stat = 1;
			}
		}
		tmove = tmove->next;

	}
	return (0);
}

int		find_l(t_rooms *rooms, t_rooms **room_l)
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

int algorithm(t_var *var)
{

	t_rooms		*room_l;

	while (find_l(var->rooms, &room_l))
	{
			find_move(var->rooms, room_l, var->moves);
	}
	return (0);
}


//int algorithm(t_var *var)
//{
//	t_move		*queue;
//	t_rooms		*room_l;
//
//	while (find_start(var->room, &room_l))
//	{
//		ft_printf("room %s  ", room_l->name);
//		if (var->room->stat != 4)
//			find_move(var->room, room_l, var->inst);
//		ft_printf("ok\n");
//	}
//	return (0);
//}



//int		find_move(t_rooms *rooms,t_rooms *start, t_move *move)
//{
//	t_move		*tmove;
//	t_rooms		*troom;
//
//	tmove = move;
//	while (tmove)
//	{
//		troom = rooms;
//		if (tmove->stat == 0 && ft_strcmp(tmove->name, start->name) == 0)
//		{
//			while (troom && ft_strcmp(troom->name, tmove->name_next))
//				troom = troom->next;
//			if (troom->lenmove > (tmove->distance + start->lenmove))
//			{
//				troom->lenmove = (tmove->distance + start->lenmove);
//				troom->prev = start;
//				tmove->stat = 1;
//				if (troom->stat != 4)
//					troom->stat = 1;
//			}
//		}
//		else if (tmove->stat == 0 && ft_strcmp(tmove->name_next, start->name) == 0)
//		{
//			while (troom && ft_strcmp(troom->name, tmove->name))
//				troom = troom->next;
//			if (troom->lenmove > tmove->distance + start->lenmove)
//			{
//				troom->lenmove = (tmove->distance + start->lenmove);
//				troom->prev = start;
//				tmove->stat = 1;
//				if (troom->stat != 4)
//					troom->stat = 1;
//			}
//		}
//		tmove = tmove->next;
//
//	}
//	return (0);
//}