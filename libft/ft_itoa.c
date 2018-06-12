/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:00:12 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 18:27:15 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*re;
	int		p;

	p = 1;
	i = ft_count(n);
	if (n < 0)
		p = -1;
	if (n < 1)
		i++;
	if (!(re = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	re[i] = '\0';
	while (i-- != 0)
	{
		re[i] = (((n % 10) * p) + '0');
		n /= 10;
	}
	if (p < 0)
		re[0] = '-';
	return (re);
}
