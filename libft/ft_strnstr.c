/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:15:48 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/05 18:45:56 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int k;
	int count;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i])
	{
		k = 0;
		count = i;
		while (little[k] && big[count++] == little[k])
			k++;
		if (count > (int)len)
			return (0);
		if (little[k] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
