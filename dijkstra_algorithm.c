
#include "lem-in.h"

int		find_start(t_rooms *troom, t_rooms **start)
{
	while (troom && troom->stat != 3)
		troom = troom->next;
	troom->lenmove = 0;
	*start = troom;
	return (0);
}

int		find_end(t_rooms *troom, t_rooms **end)
{
	while (troom && troom->stat != 4)
		troom = troom->next;
	troom->lenmove = 0;
	*end = troom;
	return (0);
}

int		find_L(t_rooms *troom, t_rooms **start)
{
	t_rooms *l;

	find_end(troom, &l);
	while (troom)
	{
		if (troom->lenmove < l->lenmove && troom->stat == 1)
			l = troom;
		troom = troom->next;
	}
	if (l->stat == 4)
		return (0);
	*start = l;
	return (1);
}

int		find_move(t_rooms **rooms,t_rooms *start, t_move **move)
{
	t_move		*tmove;
	t_rooms		*troom;

	tmove = *move;
	while (tmove)
	{
		troom = *rooms;
		if (ft_strcmp(tmove->name, start->name) == 0)
		{
			while (troom && ft_strcmp(troom->name, tmove->name_next))
				troom = troom->next;
			if (troom->lenmove == 2147483647 || troom->lenmove > tmove->distance + start->lenmove)
			{
				troom->lenmove = (tmove->distance + start->lenmove);
				tmove->stat = 1;
			}
		}
		else if (ft_strcmp(tmove->name_next, start->name) == 0)
		{
			while (troom && ft_strcmp(troom->name, tmove->name))
				troom = troom->next;
			if (troom->lenmove == 2147483647)// || troom->lenmove > tmove->distance + start->lenmove)
			{
				troom->lenmove = (tmove->distance + start->lenmove);
				tmove->stat = 1;
			}
		}
		tmove = tmove->next;
	}

	return (0);
}

void		dijkstra(t_var *var)
{
	t_rooms		*start;

	find_start(var->room, &start);
	find_move(&(var->room), start, &(var->inst));
	find_L(var->room, &start);
//	ft_printf("%d\n", start->stat);
//	find_move(&(var->room), start, &(var->inst));
//	while (find_L(var->room, &start))
//	{
//		ft_printf("asd123\n");
//		find_move(&(var->room), start, &(var->inst));
//	}
}