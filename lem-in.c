
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

void prev_list(t_rooms *room)
{
	while (room->stat != 4)
		room = room->next;
	while (room)
	{
		ft_printf("room %s ->", room->name);
		room = room->prev;
	}
	ft_printf("\n");
}

int main(void)
{
	t_var *var;

	ft_init(&var);
	read_instruction(var);
	if (var->error != 0)
	{
		if (var->error == -1)
			ft_printf("ants\n");
		else if (var->error == -1)
			ft_printf("ants\n");
		else if (var->error == -1)
			ft_printf("ants\n");
		else if (var->error == -1)
			ft_printf("ants\n");
		return (0);
	}
	//dijkstra(var);
	ft_printf("ants = %d\n\n", var->ants);
	while (var->inst)
	{
		ft_printf("name == %s\tname next == %s\t\t\tstat == %d\n", var->inst->name, var->inst->name_next, var->inst->stat);
		var->inst = var->inst->next;
	}
	//prev_list(var->room);
	while (var->room)
	{
		ft_printf("name == %s\tx == %d\t\ty == %d\t\tstat == %d\tlenm == %d\n", var->room->name, var->room->x, var->room->y, var->room->stat,
				  var->room->lenmove);
		var->room = var->room->next;
	}
}