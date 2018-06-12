/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:11:30 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/17 20:53:45 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_0x(char c)
{
	if (c == 10)
		return ('a');
	if (c == 11)
		return ('b');
	if (c == 12)
		return ('c');
	if (c == 13)
		return ('d');
	if (c == 14)
		return ('e');
	if (c == 15)
		return ('f');
	return (0);
}

static void		print_bits(int n)
{
	int			i;
	int			k;
	char		s[9];

	k = 0;
	i = 0;
	if (n < 16)
		ft_putchar((k++ + 48));
	while (n > 0)
	{
		if ((n % 16) > 9)
			s[i++] = ft_0x(n % 16);
		else
			s[i++] = ((n % 16) + 48);
		n /= 16;
	}
	while (k++ < 8)
	{
		if (i-- > 0)
			ft_putchar(s[i]);
		else
			ft_putchar('0');
		if (k == 4)
			ft_putchar(' ');
	}
}

void			ft_print_memory(const void *addr, size_t size)
{
	int			i;

	i = 0;
	size /= 4;
	while (size)
	{
		print_bits(((int *)addr)[i++]);
		ft_putchar(' ');
		size--;
		if (i % 4 == 0)
			ft_putchar('\n');
	}
}
