/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:32:57 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/15 14:34:13 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

void	ft_printf_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_printf_putchar(s[i]);
		i++;
	}
}

void	ft_printf_putstrn(char *s, int k)
{
	int	i;

	i = 0;
	while (s[i] && i < k)
	{
		ft_printf_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr_ll(unsigned long long n)
{
	if (n > 9)
	{
		ft_putnbr_ll(n / 10);
		ft_printf_putchar((n % 10) + 48);
	}
	else
		ft_printf_putchar(n + 48);
}
