
#include "lem-in.h"

//int		ft_room(char *s)
//{
//	int	i;
//	int space;
//	int	count_int;
//
//	count_int = 0;
//	space = 0;
//	i = 0;
//	while (s[i] && s[i] != ' ')
//		i++;
//	while (s[i] == ' ')
//	{
//		i++;
//		if ((s[i] > 47 && s[i] < 58) || s[i] == '-')
//		{
//			while ((s[i] > 47 && s[i] < 58) || s[i] == '-')
//				i++;
//			count_int++;
//		}
//			space++;
//	}
//	if ((s[i] != '#' && s[i] != '\0') || space != 2 || count_int != 2)
//		return (-1);
//	return (5);
//}
//
//int		room_move(char *s)
//{
//	int i;
//
//	i = 0;
//	if (s[i] == 'L')
//		return (-1);
//	while (s[i])
//	{
//		if (s[i] == ' ')
//			return (ft_room(s));
//		if (s[i] == '-')
//			return (6); //ft_move(s);
//		i++;
//	}
//	return (0);
//}
//
//int if_start_end_com(char *s)
//{
//	if (ft_strncmp(s, "##start", 7) == 0)
//	{
//		if (s[7] != '\0' && s[7] != '#')
//			return (-1);
//		return (3);
//	}
//	else if (ft_strncmp(s, "##end", 5) == 0)
//	{
//		if (s[5] != '\0' && s[5] != '#')
//			return (-1);
//		return (4);
//	}
//	else if (s[0] == '#' && s[1] == '#')
//		return (-1);
//	else if (s[0] == '#')
//		return (1);
//	return (0);
//}
//
//int check_comment(char *s, int n)
//{
//	if (s[n] == '#')
//		return (0);
//	return (1);
//}
//
//int inst_cmp(char *s, int error)
//{
//	error = if_start_end_com(s);
//	if (error == 0)
//	{
//		error = room_move(s);
//	}
//	return (error);
//}