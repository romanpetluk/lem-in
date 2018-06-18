
#include "lem-in.h"

int			ft_atoi_lem(char *str)
{
	int		i;
	long	re;
	int		n;

	if (str)
	{
		re = 0;
		n = 1;
		i = 0;
		if (str[i] == '-')
			n = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			re *= 10;
			re += ((str[i] - 48) * n);
			i++;
		}
		if (str[i] != '\0' && str[i] != '#')
			return (-1);
		return ((int)(re));
	}
	return (-1);
}

int			read_instruction_ants(char *s, t_var *var)
{
	var->ants = ft_atoi_lem(s);
	if (var->ants < 0)
	{
		var->error = var->ants;
		return (var->error -1);
	}
	var->grup_valid++;
	return (1);
}