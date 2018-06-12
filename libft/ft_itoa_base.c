/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:30:08 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/15 09:51:00 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(int n, int c)
{
	int			i;

	i = 0;
	while (n != 0)
	{
		n /= c;
		i++;
	}
	return (i);
}

static	char	ft_0x(int x)
{
	if (x == 10)
		return ('A');
	else if (x == 11)
		return ('B');
	else if (x == 12)
		return ('C');
	else if (x == 13)
		return ('D');
	else if (x == 14)
		return ('E');
	else if (x == 15)
		return ('F');
	return (0);
}

static	int		ft_mp(int n, int p)
{
	if (n < 0)
		p = -1;
	return (p);
}

static	int		ft_imal(int n, int i)
{
	if (n < 0)
		i++;
	return (i);
}

char			*ft_itoa_base(int n, int c)
{
	int			i;
	int			k;
	int			p;
	char		*ret;

	i = ft_count(n, c);
	p = 1;
	k = 0;
	p = ft_mp(n, p);
	i = ft_imal(n, i);
	if (!(ret = (char *)malloc(sizeof(char) * (i))))
		return (NULL);
	ret[i--] = '\0';
	while (n != 0)
	{
		if (n % c > 9 && n % c < 16)
			ret[i] = ft_0x(n % c);
		else
			ret[i] = (((n % c) * p) + '0');
		n /= c;
		i--;
	}
	if (p < 0)
		ret[i] = '-';
	return (ret);
}
