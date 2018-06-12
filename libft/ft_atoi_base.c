/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:40:06 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/17 19:10:24 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_0x(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	if (c == 'b' || c == 'B')
		return (11);
	if (c == 'c' || c == 'C')
		return (12);
	if (c == 'd' || c == 'D')
		return (13);
	if (c == 'e' || c == 'E')
		return (14);
	if (c == 'f' || c == 'F')
		return (15);
	return (0);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int			i;
	int			k;
	int			n;

	n = 1;
	i = 0;
	k = 0;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while ((str[i] - 48 >= 0 && str[i] - 48 < str_base) ||
		(str[i] > 96 && str[i] < 103) || (str[i] > 64 && str[i] < 91))
	{
		k *= str_base;
		if ((str[i] - 48 >= 0 && str[i] - 48 < 9))
			k += ((str[i] - '0') * n);
		else
			k += (ft_0x(str[i]) * n);
		i++;
	}
	return (k);
}
