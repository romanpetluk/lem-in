/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:09:10 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:10:25 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_start(char *s, t_var *var)
{
	int		i;

	i = 7;
	while (s[i] == ' ' || s[i] == '\0' || s[i] == '#')
	{
		if (s[i] == '\0' || s[i] == '#')
		{
			if (var->start_count != 0)
				return (var->error = -9);
			if (var->comand != 0)
				return (var->error = -11);
			var->comand = 3;
			var->start_count = 1;
			return (0);
		}
		i++;
	}
	return (0);
}

static int	check_end(char *s, t_var *var)
{
	int		i;

	i = 5;
	while (s[i] == ' ' || s[i] == '\0' || s[i] == '#')
	{
		if (s[i] == '\0' || s[i] == '#')
		{
			if (var->end_count != 0)
				return (var->error = -10);
			if (var->comand != 0)
				return (var->error = -11);
			var->comand = 4;
			var->end_count = 1;
			return (0);
		}
		i++;
	}
	return (var->error = -1);
}

static int	check_comment_adn_command(char *s, t_var *var)
{
	if (ft_strncmp(s, "##start", 7) == 0)
	{
		if (check_start(s, var))
			return (-1);
	}
	else if (ft_strncmp(s, "##end", 5) == 0)
	{
		if (check_end(s, var))
			return (-1);
	}
	if (var->comand && var->grup_valid == 0)
		var->error = -12;
	return (0);
}

static int	validate_str(char *s, t_var *var)
{
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (var->error = -3);
	else if (s[i] == '#')
		return (1);
	return (0);
}

int			read_instruction(t_var *var)
{
	char	*s;
	char	*ssave;

	while (get_next_line(0, &ssave))
	{
		s = ft_strtrim(ssave);
		var->bon.count_line++;
		if (var->comand && var->grup_valid == 2)
			var->error = -13;
		else if (!var->error && validate_str(s, var) > 0)
			check_comment_adn_command(s, var);
		else if (!var->error && var->grup_valid == 0)
			read_instruction_ants(s, var);
		else if (!var->error && var->grup_valid == 1)
			read_instruction_room(s, var);
		else if (!var->error && var->grup_valid == 2)
			read_instruction_move(s, var);
		free(s);
		if (var->error)
			ft_errors(var);
		add_string_txt(ssave, &var->txt);
	}
	return (0);
}
