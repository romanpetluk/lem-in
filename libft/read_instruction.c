
#include "lem-in.h"

static int check_start(char *s, t_var *var)
{
	int i;

	i = 7;
	while (s[i] == ' ' || s[i] == '\0' || s[i] == '#')
	{
		if (s[i] == '\0' || s[i] == '#')
		{
			if (var->start == 0 && var->start_count == 0)
			{
				var->start = 3;
				var->start_count = 1;
				return (0);
			}
			else
				return (var->error = -1);
		}
		i++;
	}
	return (var->error = -1);
}

static int check_end(char *s, t_var *var)
{
	int i;

	i = 5;
	while (s[i] == ' ' || s[i] == '\0' || s[i] == '#')
	{
		if (s[i] == '\0' || s[i] == '#')
		{
			if (var->start == 0 && var->end_count == 0)
			{
				var->start = 4;
				var->end_count = 1;
				return (0);
			}
			else
				return (var->error = -1);
		}
		i++;
	}
	return (var->error = -1);
}

int check_comment_adn_command(char *s, t_var *var)
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
	if (s[0] == '#')
	{
		free(s);
		s = NULL;
		return (1);
	}
	return (0);
}

int read_instruction(t_var *var)
{
	char	*s;

	while (get_next_line(0, &s))
	{
		if (s[0] == '#')
			while (check_comment_adn_command(s, var) == 1)
				get_next_line(0, &s);
		if (var->grup_valid == 0 && !var->start)
			read_instruction_ants(s, var);
		else if (var->grup_valid == 1 && var->error == 0)
		{
			read_instruction_room(s, var);
			//ft_printf("grup == %d\n", var->grup_valid);
		}
		if (var->grup_valid == 2 && !var->start && var->error > -1)
		{
			read_instruction_move(s, var);
		}
		if (var->error)
			return (var->error);
		free(s);
		s = NULL;
	}
	return (0);
}
