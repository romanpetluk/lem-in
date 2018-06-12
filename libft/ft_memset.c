/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:47:38 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 17:21:04 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*rt;

	i = 0;
	rt = (unsigned char *)b;
	while (i < len)
	{
		rt[i] = c;
		i++;
	}
	return (void *)rt;
}
