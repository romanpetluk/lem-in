/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:10:47 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 17:12:45 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[c])
		c++;
	if (!(res = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	while (s[i])
	{
		res[i] = ((char *)s)[i];
		i++;
	}
	i = 0;
	while (s[i])
	{
		res[i] = f(res[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
