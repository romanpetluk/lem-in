
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
//	temp->i = 1;
//	temp->fd = 1;
//	temp->med_a = 0;
//	temp->med_b = 0;
//	temp->grp = 0;
//	temp->count_ra = 0;
	*var = temp;
	return (1);
}

int main(void)
{
	t_var *var;

	ft_init(&var);
	read_instruction(var);
	dijkstra(var);
	ft_printf("ants = %d\n\n", var->ants);
	while (var->inst)
	{
		ft_printf("name == %s\tname next == %s\t\t\tstat == %d\n", var->inst->name, var->inst->name_next, var->inst->stat);
		var->inst = var->inst->next;
	}
	while (var->room)
	{
		ft_printf("name == %s\tx == %d\t\ty == %d\t\tstat == %d\n", var->room->name, var->room->x, var->room->y, var->room->stat);
		var->room = var->room->next;
	}
}