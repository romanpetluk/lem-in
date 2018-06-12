/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putbase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:46:02 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/19 16:21:06 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_basenwidth(unsigned long long n, t_flag *flags)
{
	if (flags->sign == 2)
		flags->width--;
	if (!n && flags->accuracy < 0)
		flags->width--;
	else if (flags->sign == 1 && flags->p == 2)
		flags->width--;
	if (flags->accuracy < 0)
		while (n != 0)
		{
			n /= 8;
			flags->width--;
		}
	else
	{
		while (n != 0)
		{
			n /= 8;
			flags->width--;
			flags->accuracy--;
		}
		if (flags->accuracy > 0)
			flags->width -= flags->accuracy;
	}
}

static void	ft_printf_putbase(unsigned long long n)
{
	if (n > 7)
	{
		ft_printf_putbase(n / 8);
		ft_printf_putchar((n % 8) + 48);
	}
	else
		ft_printf_putchar(n + 48);
}

void		ft_putnbr_base_width(unsigned long long n, t_flag flags)
{
	if (flags.p == 1 && flags.accuracy > -1)
		flags.p = 0;
	if (flags.accuracy > -1 && !n)
		flags.n = 0;
	if (flags.width > 0 || flags.accuracy > -1)
		ft_printf_basenwidth(n, &flags);
	if (flags.hesh == 1 && flags.accuracy < 1 && n)
		flags.width--;
	if (flags.p != 2)
		ft_printf_widthnbr(&flags);
	if ((flags.hesh == 1 && flags.accuracy < 0 && n) ||
		(flags.hesh == 1 && flags.accuracy > -1))
	{
		ft_printf_putchar('0');
		flags.accuracy--;
	}
	while (flags.accuracy > 0)
	{
		ft_printf_putchar('0');
		flags.accuracy--;
	}
	if (flags.n)
		ft_printf_putbase(n);
	if (flags.p == 2)
		ft_printf_widthnbr(&flags);
}

void		ft_putnbr_basex_width(unsigned long long n, t_flag flags)
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
		ft_printf_putchar('x');
	}
	if (flags.p != 2)
		ft_printf_widthnbr(&flags);
	if (flags.hesh == 1 && flags.p != 1 && n)
	{
		ft_printf_putchar('0');
		ft_printf_putchar('x');
	}
	while (flags.accuracy-- > 0)
		ft_printf_putchar('0');
	if (flags.n)
		ft_printf_putbasex(n);
	if (flags.p == 2)
		ft_printf_widthnbr(&flags);
}
