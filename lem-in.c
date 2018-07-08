
#include "lem-in.h"

static int		ft_init(t_var **var)
{
	t_var		*temp;

	if (!(temp = (t_var*)malloc(sizeof(t_var))))
		return (0);
	temp->room = NULL;
	temp->inst = NULL;
	temp->ants = 0;
	temp->start = 0;
	temp->error = 0;
	temp->start_count = 0;
	temp->end_count = 0;
	temp->grup_valid = 0;
	*var = temp;
	return (1);
}

void way_list(t_way *way)
{
	while (way)
	{
//		way->room->stat = status;
		ft_printf("room %s", way->room->name);
		way = way->next_room;
		if (way)
			ft_printf(" ->");
	}
	ft_printf("\n");
}

void write_room(t_rooms *room)
{
	ft_printf("ASD\n");
	while (room && room->stat != 4)
		room = room->next;
	ft_printf("ASD\n");
	while (room)
	{
		ft_printf("room %s", room->name);
		room = room->prev;
		if (room)
			ft_printf(" ->");
	}
}

void add_way(t_rooms *room, t_way **way)
{
	t_rooms *troom;
	t_way *tway;

	troom = room;
	tway = NULL;
	while (troom->stat != 4)
		troom = troom->next;
	while (troom)
	{
		ft_newlist_way(&tway);
		troom->stat = 3;
		tway->room = troom;
		troom = troom->prev;
	}
	*way = tway;
}
static void reset_stat_room(t_rooms *rooms)
{
	while (rooms)
	{
		if (rooms->stat == 2)
			rooms->stat = 0;
		rooms = rooms->next;
	}
}

int main(void)
{
	t_var *var;
	t_way *way;
	t_way *way1;

	way1 = NULL;
	way = NULL;
	ft_init(&var);
	read_instruction(var);
//	if (var->error != 0)
//	{
//		if (var->error == -1)
//			ft_printf("ants\n");
//		else if (var->error == -1)
//			ft_printf("ants\n");
//		else if (var->error == -1)
//			ft_printf("ants\n");
//		else if (var->error == -1)
//			ft_printf("ants\n");
//		return (0);
//	}


	algorithm(var);
	add_way(var->room, &way);
	reset_stat_room(var->room);
	way_list(way);

	algorithm(var);

	//add_way(var->room, &way1);
	write_room(var->room);


	ft_printf("ants = %d\n\n", var->ants);
	while (var->inst)
	{
		ft_printf("name == %s\tname next == %s\t\t\tstat == %d\n", var->inst->name, var->inst->name_next, var->inst->stat);
		var->inst = var->inst->next;
	}
	ft_printf("\n");
	while (var->room)
	{
		ft_printf("name == %s\tx == %d\t\ty == %d\t\tstat == %d\tlenm == %d\n", var->room->name, var->room->x, var->room->y, var->room->stat,
				  var->room->lenmove);
		var->room = var->room->next;
	}
}