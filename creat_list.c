
#include "lem-in.h"

static int		ft_init_move(char *s, t_move **new)
{
	char		**split;

	split = ft_strsplit(s, '-');

	(*new)->name = split[0];
	(*new)->name_next = split[1];
	(*new)->stat = 0;
	(*new)->distance = 1;
	free(split[2]);
	free(split);
	split = NULL;
	return (0);
}

static int		ft_newlist_move(char *s, t_move **inst)
{
	t_move		*new;
	t_move		*temp;

	temp = *inst;
	if (!(new = (t_move *)malloc(sizeof(t_move))))
		return (-1);
	new->next = NULL;
	ft_init_move(s, &new);
	if (*inst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*inst = new;
	return (1);
}

static int		ft_init_room(char *s, t_rooms **new, int start)
{
	char		**split;

	split = ft_strsplit(s, ' ');
	(*new)->name = split[0];
	(*new)->x = ft_atoi(split[1]);
	(*new)->y = ft_atoi(split[2]);
	(*new)->ant = 0;
	(*new)->stat = 0;
	(*new)->lenmove = 2147483647;
	(*new)->stat = start;
	(*new)->prev = NULL;
	free(split[1]);
	free(split[2]);
	free(split[3]);
	free(split);
	split = NULL;
	return (0);
}

static int		ft_newlist_room(char *s, t_rooms **room, int start)
{
	t_rooms		*new;
	t_rooms		*temp;

	temp = *room;
	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (-1);
	new->next = NULL;
	ft_init_room(s, &new, start);
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

void creat_list(char *s, t_var *var, int cmp)
{
	if (cmp == 5)
	{
		ft_newlist_room(s, &(var->room), var->start);
		var->start = 0;
	}
	if (cmp == 6)
	ft_newlist_move(s, &(var->inst));
}
