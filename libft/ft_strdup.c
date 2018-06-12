/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:49:34 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/05 16:57:11 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*buf;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if ((buf = (char*)malloc(sizeof(char) * (i + 1))) == 0)
		return (NULL);
	buf[i] = '\0';
	i = 0;
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	return (buf);
}
