
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

//int ft_room(char *s)
//{
//	int i;
//	int space;
//
//	space = 0;
//	i = 0;
//	while (s[i])
//	{
//		i++;
//	}
//}

//int ft_move(char *s, char c)
//{
//	int i;
//	int space;
//	int count;
//
//	space = 0;
//	i = 0;
//	count = 0;
//	//ref...
//	if (s[i] == c)
//		return (0);
//	//
//	while (s[i])
//	{
//		if (s[i] > 47 && s[i] < 58)
//		{
//			while (s[i] > 47 && s[i] < 58)
//				i++;
//			count++;
//
//		}
//		else if (s[i] == c)
//		{
//			space++;
//			i++;
//		}
//		else
//			return (-1);
//	}
//	if (space == 1 && num == 2)
//		return (5);
//	return (0);
//}
//
//int room_or_move(char *s)
//{
//	int i;
//
//	i = 0;
//	while (s[i])
//	{
//		if (s[i] == ' ')
//			ft_room(s);
//		if (s[i] == '-')
//			ft_move(s);
//		i++;
//	}
//	return (0);
//}

int inst_cmp(char *s)
{
	int i;

	i = 0;
	if (ft_strcmp(s, "##start") == 0)
		return (3);
	else if (ft_strcmp(s, "##end") == 0)
		return (4);
	else if (s[0] == '#')
		return (1);
	while (s[i])
	{
		while (s[i] > 47 && s[i] < 58)
			i++;
		if (s[i] == '\0')
			return (2);
		if (s[i] == ' ')
			return (5);
		if (s[i] == '-')
			return (6);
		i++;
	}
	return (0);
}