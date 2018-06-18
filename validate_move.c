
#include "lem-in.h"

void free_fail(char **split)
{
	int			end_split;

	end_split = 0;
	while (split[end_split] != 0)
	{
		free(split[end_split]);
		end_split++;
	}
	free(split[end_split]);
	free(split);
	split = NULL;
}

static int		cmp_name(t_rooms *room, char *s)
{
	while (room)
	{
		if (ft_strcmp(room->name, s) == 0)
		{
			return (0);
		}
		room = room->next;
	}
	return (1);
}

static int count_split_and_free(char **split)
{
	int count;

	count = 0;
	while (split[count] != 0)
		count++;
	if (count > 1)
	{
		count = 2;
		if (split[count] == 0)
		{
			free(split[count]);
			return (0);
		}
		else if (split[count][0] == '#')
		{
			while (split[count] != 0)
				free(split[count++]);
			free(split[count]);
			return (0);
		}
	}
	free_fail(split);
	return (1);
}

int read_instruction_move(char *s, t_var *var)
{
	char		**split;

	split = ft_strsplit(s, '-');
	if (count_split_and_free(split))
		return (var->error = -1);
	if (cmp_name(var->room, split[0]))
		return (var->error = -1);
	if (cmp_name(var->room, split[1]))
		return (var->error = -1);
	ft_newlist_move(split, &(var->inst));
	return (0);
}