/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putbasex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:49:52 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/19 16:23:12 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_0x(int x)
{
	if (x == 10)
		return ('a');
	else if (x == 11)
		return ('b');
	else if (x == 12)
		return ('c');
	else if (x == 13)
		return ('d');
	else if (x == 14)
		return ('e');
	else if (x == 15)
		return ('f');
	return (0);
}

void		ft_printf_basexnwidth(unsigned long long n, t_flag *flags)
{
	if (flags->hesh == 1 && n)
		flags->width -= 2;
	if (!n && flags->accuracy < 0)
		flags->width--;
	if (flags->sign == 2)
		flags->width--;
	if (flags->sign == 1 && flags->p == 2)
		flags->width--;
	if (flags->accuracy < 0)
		while (n != 0)
		{
			n /= 16;
			flags->width--;
		}
	else
	{
		while (n != 0)
		{
			n /= 16;
			flags->width--;
			flags->accuracy--;
		}
		if (flags->accuracy > 0)
			flags->width -= flags->accuracy;
	}
}

void		ft_printf_putbasex(unsigned long long n)
{
	if (n > 15)
	{
		ft_printf_putbasex(n / 16);
		if (n % 16 < 10)
			ft_printf_putchar((n % 16) + 48);
		else
			ft_printf_putchar(ft_0x(n % 16));
	}
	else
	{
		if (n % 16 < 10)
			ft_printf_putchar((n % 16) + 48);
		else
			ft_printf_putchar(ft_0x(n % 16));
	}
}

static void	ft_printf_putbasexx(unsigned long long n)
{
	if (n > 15)
	{
		ft_printf_putbasexx(n / 16);
		if (n % 16 < 10)
			ft_printf_putchar((n % 16) + 48);
		else
			ft_printf_putchar(ft_0x(n % 16) - 32);
	}
	else
	{
		if (n % 16 < 10)
			ft_printf_putchar((n % 16) + 48);
		else
			ft_printf_putchar(ft_0x(n % 16) - 32);
	}
}

void		ft_putnbr_basexx_width(unsigned long long n, t_flag flags)
{
	if (flags.p == 1 && flags.accuracy > -1)
		flags.p = 0;
	if (flags.accuracy > -1 && !n)
		flags.n = 0;
	if (flags.width > 0 || flags.accuracy > -1)
		ft_printf_basexnwidth(n, &flags);
	if (flags.hesh == 1 && flags.p == 1 && n)
	{
		ft_printf_putchar('0');
		ft_printf_putchar('X');
	}
	if (flags.p != 2)
		ft_printf_widthnbr(&flags);
	if (flags.hesh == 1 && flags.p != 1 && n)
	{
		ft_printf_putchar('0');
		ft_printf_putchar('X');
	}
	while (flags.accuracy-- > 0)
		ft_printf_putchar('0');
	if (flags.n)
		ft_printf_putbasexx(n);
	if (flags.p == 2)
		ft_printf_widthnbr(&flags);
}
