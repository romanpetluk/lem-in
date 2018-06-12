/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:57:06 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/12 17:04:44 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		k;
	int		count;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i] != '\0')
	{
		k = 0;
		count = i;
		while (little[k] && big[count++] == little[k])
			k++;
		if (little[k] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
