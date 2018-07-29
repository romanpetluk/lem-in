/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:17:55 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:19:45 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	validate_name_hyphen(char *split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		if (split[i] == '-')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	validate_coord(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (-1);
	while (s[i] > 47 && s[i] < 58)
		i++;
	if (s[i] == '\0')
		return (1);
	if (s[i] == '#')
		return (2);
	return (-1);
}

static int	count_split_and_free(char **split)
{
	int		count;

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

static int	cmp_name(t_rooms *room, char **split)
{
	while (room)
	{
		if (ft_strcmp(room->name, split[0]) == 0)
			return (1);
		else if (room->x == ft_atoi(split[1]) && room->y == ft_atoi(split[2]))
			return (1);
		room = room->next;
	}
	return (0);
}

int			read_instruction_room(char *s, t_var *var)
{
	char	**split;

	if (s[0] == 'L')
		return (var->error = -2);
	split = ft_strsplit(s, ' ');
	if (validate_name_hyphen(split[0]))
	{
		free_fail(split);
		if (var->comand)
			return (var->error = -11);
		var->grup_valid++;
		if (!read_instruction_move(s, var))
			return (0);
		return (var->error = -15);
	}
	if (count_split_and_free(split))
		return (var->error = -5);
	if (validate_coord(split[1]) != 1)
		return (var->error = -6);
	if (validate_coord(split[2]) < 0)
		return (var->error = -7);
	if (cmp_name(var->rooms, split))
		return (var->error = -8);
	ft_newlist_room(split, &(var->rooms), var->comand);
	var->comand = 0;
	return (0);
}
