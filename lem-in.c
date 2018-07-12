
#include "lem-in.h"

static int		ft_init(t_var **var)
{
	t_var		*temp;

	if (!(temp = (t_var*)malloc(sizeof(t_var))))
		return (0);
	temp->rooms = NULL;
	temp->moves = NULL;
	temp->ants = 0;
	temp->start = 0;
	temp->error = 0;
	temp->start_count = 0;
	temp->end_count = 0;
	temp->grup_valid = 0;
	*var = temp;
	return (1);
}

//void write_room(t_rooms *rooms)
//{
//	ft_printf("ASD\n");
//	while (rooms && rooms->stat != 4)
//		rooms = rooms->next;
//	ft_printf("ASD\n");
//	while (rooms)
//	{
//		ft_printf("rooms %s", rooms->name);
//		rooms = rooms->prev;
//		if (rooms)
//			ft_printf(" ->");
//	}
//}

void add_way(t_rooms *room, t_way **way)
{
	t_way *tway;

	tway = *way;
	if (tway)
	{
		ft_printf("QWE\n");
		ft_printf("ASD\n");
		while (tway->next_way)
			tway = tway->next_way;
	}
	while (room->stat != 4)
		room = room->next;

	while (room)
	{
		ft_newlist_way(&tway);
		room->stat = 3;
		tway->room = room;
		room = room->prev;
	}
	if (!*way)
		*way = tway;
}
//static void reset_stat_room(t_rooms *rooms)
//{
//	while (rooms)
//	{
//		if (rooms->stat == 2)
//			rooms->stat = 0;
//		rooms = rooms->next;
//	}
//}

void way_list(t_way *way)
{
	t_way *tway;

	while (way)
	{
		tway = way;
		while (tway)
		{
//		way->rooms->stat = status;
			ft_printf("rooms %s", tway->room->name);
			tway = tway->next_room;
			if (tway)
				ft_printf(" ->");
		}
		ft_printf("\n");
		way = way->next_way;
	}
}

void check_start(t_rooms *rooms)
{
	while (rooms)
	{
		ft_printf("ROOM %s start %d \n",rooms->name ,rooms->start);
		rooms = rooms->next;
	}
}

int main(void)
{
	t_var *var;
	t_way *way;

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

//	check_start(var->rooms);

	algorithm(var);
	add_way(var->rooms, &way);
	//reset_stat_room(var->rooms);
	way_list(way);
//
//	//algorithm(var);
//	way_list(way);

	//add_way(var->rooms, &way);
//	write_room(var->rooms);


	ft_printf("ants = %d\n\n", var->ants);
	while (var->moves)
	{
		ft_printf("name == %s\tname next == %s\n", var->moves->name, var->moves->name_next);
		var->moves = var->moves->next;
	}
	ft_printf("\n");
	while (var->rooms)
	{
		ft_printf("name == %s\tx == %d\t\ty == %d\t\tstat == %d\tlenm == %d\n", var->rooms->name, var->rooms->x, var->rooms->y, var->rooms->stat,
				  var->rooms->lenmove);
		var->rooms = var->rooms->next;
	}
}