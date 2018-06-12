/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:01:30 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 17:36:15 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	c = 0;
	i = 0;
	while (s1[c])
		c++;
	while (s2[i])
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + c + 1))))
		return (NULL);
	c = -1;
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++c])
	{
		res[i] = s2[c];
		i++;
	}
	res[i] = '\0';
	return (res);
}
