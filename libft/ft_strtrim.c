/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:17:33 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 18:26:22 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_sok(char *res, char const *s, int i, int c)
{
	int		k;

	k = 0;
	while (i <= c)
	{
		res[k] = s[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*res;
	int		c;

	c = 0;
	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' && s[i]) || (s[i] == '\t' && s[i]) ||
		(s[i] == '\n' && s[i]))
		i++;
	while (s[c + 1])
		c++;
	while ((s[c] == ' ' && s[i]) || (s[c] == '\t' && s[i]) ||
		(s[c] == '\n' && s[i]))
		c--;
	if (!(res = (char *)malloc(sizeof(char) * (c - i + 2))))
		return (NULL);
	res = ft_sok(res, s, i, c);
	return (res);
}
