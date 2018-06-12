
#include "lem-in.h"

//int ft_atoi_lem(char *s, int *i)
//{
//	long num;
//
//	num = 0;
//	while (s[i] > 47 && s[i] < 58)
//	{
//		num *= 10;
//		num += (s[i] - 48);
//	}
//	if (s[i] == '\0' || s[i] == c)
//		return (num);
//	return (-1);
//}

int read_instruction(t_var *var)
{
	int		i;
	char	*s;
	int		cmp;

	i = 0;
	while (get_next_line(0, &s))
	{
		cmp = inst_cmp(s);
		if (cmp == 3 || cmp == 4)
			var->start = cmp;
		else if (cmp == 2)
			var->ants = atoi(s);
//		if (cmp == 0)
//			return (-1);
		else
			creat_list(s, var, cmp);
	}
	return (0);
}