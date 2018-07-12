
#include "lem-in.h"

static int		ft_init_move(t_move **new, char *r_name1, char *r_name2)
{
	(*new)->name = r_name1;
	(*new)->name_next = r_name2;
	//(*new)->stat = 0;
	(*new)->distance = 1;
	return (0);
}

int		ft_newlist_move(t_move **moves, char *r_name1, char *r_name2)
{
	t_move		*new;
	t_move		*temp;

	temp = *moves;
	if (!(new = (t_move *)malloc(sizeof(t_move))))
		return (-1);
	new->next = NULL;
	ft_init_move(&new, r_name1, r_name2);
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
	(*new)->name = s[0];
	(*new)->x = ft_atoi(s[1]);
	(*new)->y = ft_atoi(s[2]);
	(*new)->stat = 0;
	(*new)->start = 0;
	(*new)->lenmove = 2147483647;
	(*new)->stat = comand;
	(*new)->prev = NULL;
	free(s[1]);
	free(s[2]);
	free(s);
	s = NULL;
	return (0);
}

int		ft_newlist_room(char **s, t_rooms **room, int comand)
{
	t_rooms		*new;
	t_rooms		*temp;

	temp = *room;
	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (-1);
	new->next = NULL;
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

int		ft_newlist_way(t_way **way)
{
	t_way		*new;

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		return (-1);
	new->room = NULL;
	new->next_room = NULL;
	new->next_way = NULL;
	new->stat = 0;
	new->distance = 0;
	if (*way)
		new->next_room = *way;
	*way = new;
	return (1);
}

//int		ft_newlist_room(char **s, t_rooms **room, int start)
//{
//	t_rooms		*new;
//	t_rooms		*temp;
//
//	temp = *room;
//	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
//		return (-1);
//	new->next = NULL;
//	ft_init_room(s, &new, start);
//	if (*room)
//	{
//		while (temp->next)
//			temp = temp->next;
//		temp->next = new;
//	}
//	else
//		*room = new;
//	return (1);
//}

//void creat_list(char *s, t_var *var, int cmp)
//{
//	if (cmp == 5)
//	{
//		ft_newlist_room(s, &(var->room), var->start);
//		var->start = 0;
//	}
//	if (cmp == 6)
//	ft_newlist_move(s, &(var->moves));
//}
