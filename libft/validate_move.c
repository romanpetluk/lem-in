
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
	char **split2;
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

int repeat_move(char **split, t_move *move)
{
	while (move)
	{
		if (ft_strcmp(split[0], move->name) == 0 && ft_strcmp(split[1], move->name_next) == 0)
			return (0);
		if (ft_strcmp(split[1], move->name) == 0 && ft_strcmp(split[0], move->name_next) == 0)
			return (0);
		move = move->next;
	}
	ft_printf("\n\n");
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
	if (repeat_move(split, var->inst))
		ft_newlist_move(split, &(var->inst));
	return (0);
}