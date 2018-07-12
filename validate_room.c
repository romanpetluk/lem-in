
#include "lem-in.h"

static int validate_name_hyphen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int validate_coord(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] > 47 && s[i] < 58)
		i++;
	if (s[i] == '\0')
		return (1);
	if (s[i] == '#')
		return (2);
	return (0);

}

static int count_split_and_free(char **split)
{
	int count;

	count = 0;
	while (split[count] != 0)
		count++;
	if (count > 2)
	{
		count = 3;
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

static int		cmp_name(t_rooms *room, char *s)
{
	while (room)
	{
		if (ft_strcmp(room->name, s) == 0)
			return (1);
		room = room->next;
	}
	return (0);
}

int read_instruction_room(char *s, t_var *var)
{
	char		**split;

	if (s[0] == 'L' || s[0] == '\0')
		return (var->error = -1);
	split = ft_strsplit(s, ' ');
	if (validate_name_hyphen(split[0]))
	{
		var->grup_valid++;
		return (1);
	}
	if (count_split_and_free(split))
		return (var->error = -1);
	if (validate_coord(split[1]) == 1)
		ft_atoi(split[1]);
	else
		return (var->error = -1);
	if (validate_coord(split[2]))
		ft_atoi(split[1]);
	else
		return (var->error = -1);
	if (cmp_name(var->rooms, split[0]))
		return (var->error = -1);
	ft_newlist_room(split, &(var->rooms), var->start);
	var->start = 0;
	return (0);
}