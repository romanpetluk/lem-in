/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:04:07 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 18:24:12 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (count);
}

static char	**ft_zap(char **mal, char const *s, char c)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	while (s[k] && ft_words(s, c))
	{
		l = 0;
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
		{
			mal[i][l] = s[k];
			l++;
			k++;
		}
		mal[i][l] = '\0';
		while (s[k] == c && s[k])
			k++;
		i++;
	}
	mal[i] = 0;
	return (mal);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mc;
	int		k;
	int		count;
	int		i;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(mc = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (NULL);
	while (s[i] && ft_words(s, c))
	{
		count = 0;
		while (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		while (s[i] == c && s[i])
			i++;
		if (!(mc[k++] = (char *)malloc(sizeof(char) * (count + 1))))
			return (NULL);
	}
	return (ft_zap(mc, s, c));
}
