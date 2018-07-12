
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

static void free_failn(char **split, int count)
{
	int			end_split;

	end_split = count;
	while (split[end_split] != 0)
	{
		free(split[end_split]);
		end_split++;
	}
	free(split[end_split]);
	free(split);
	split = NULL;
}

static int if_space(char **split)
{
	int i;
	char **split2;
	char *str;

	str = *split;
	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i] == ' ')
	{
		split2 = ft_strsplit(str, ' ');
		if (split2[1] == 0 || split2[1][0] == '#')
		{
			free (*split);
			*split = split2[0];
			free_failn(split2, 1);
			return (0);
		}
		else
		{
			free_fail(split2);
			return (-1);
		}
	}
	return (0);
}

static int count_split_and_free(char **split)
{
	int count;

	count = 0;
	while (split[count] != 0)
		count++;
	if (count == 2)
	{
		if (if_space(&split[1]))
			return (-1);
		free(split[count]);
		return (0);
	}
	free_fail(split);
	return (-1);
}

int repeat_move(t_move *move, char *r_name1, char *r_name2)
{
	while (move)
	{
		if (r_name1 == move->name && r_name2 == move->name_next)
			return (0);
		if (r_name2 == move->name && r_name1 == move->name_next)
			return (0);
		move = move->next;
	}
	return (1);
}

static int valid_move(t_move **moves, t_rooms *room, char **split)
{
	char *r_name1;
	char *r_name2;

	r_name1 = NULL;
	r_name2 = NULL;
	while (room)
	{
		if (ft_strcmp(room->name, split[0]) == 0)
			r_name1 = room->name;
		else if (ft_strcmp(room->name, split[1]) == 0)
			r_name2 = room->name;
		if (r_name1 && r_name2)
		{
			if (repeat_move(*moves, r_name1, r_name2))
			ft_newlist_move(moves, r_name1, r_name2);
			return (0);
		}
		room = room->next;
	}
	return (-1);
}

int read_instruction_move(char *s, t_var *var)
{
	char		**split;

	split = ft_strsplit(s, '-');
	if (count_split_and_free(split))
		return (var->error = -1);
	if (valid_move(&(var->moves), var->rooms, split))
		return (var->error = -1);
	return (0);
}