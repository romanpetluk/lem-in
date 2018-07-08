
#include "lem-in.h"



//int		find_move(t_rooms *rooms,t_rooms *start, t_move *move)
//{
//	t_move *tmove;
//	t_rooms *troom;
//
//	tmove = move;
//	while (tmove)
//	{
//		troom = rooms;
//		while (tmove->stat == 1)
//			tmove = tmove->next;
//		if (ft_strcmp(tmove->name, start->name) == 0)
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
//				else
//					ft_printf("\nasd ASD\n");
//			}
//		}
//		else if (ft_strcmp(tmove->name_next, start->name) == 0)
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
//				else
//					ft_printf("\nasd ASD\n");
//			}
//		}
//		ft_printf("dot %s  ", tmove->name);
//		tmove = tmove->next;
//	}
//}