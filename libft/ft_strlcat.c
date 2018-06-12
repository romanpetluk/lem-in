/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:58:55 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/17 20:59:10 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	dst_size;

	if (!dst && *src == '\0' && !size)
		return (0);
	dst_size = ft_strlen(dst);
	if (size)
	{
		c = 0;
		while (src[c] && (dst_size + c) < size - 1)
		{
			dst[dst_size + c] = src[c];
			c++;
		}
		dst[dst_size + c] = 0;
	}
	if (dst_size < size)
		return (dst_size + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
