/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:32:41 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/20 09:41:51 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf_find_flag(char c, t_flag *flags)
{
	if (c == 'c' || c == 'd' || c == 'D' || c == 'i' || c == 's')
		return (1);
	if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
	{
		flags->sign = 0;
		return (2);
	}
	if (c == 'C' || c == 'S')
		return (2);
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (3);
	if ((c > 48 && c < 59) || c == '.' || c == '*')
		return (4);
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (5);
	return (0);
}

void		ft_printf_unis(wchar_t *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		ft_make_unicode(s[i]);
		i++;
	}
}

void		ft_printf_widthnbr(t_flag *flags)
{
	char	sig;

	if (flags->sign == 2 && flags->p == 1)
		ft_printf_putchar('+');
	else if (flags->sign == 1 && flags->p == 1)
		ft_printf_putchar(' ');
	if (flags->p == 1 && flags->accuracy < 0)
		sig = '0';
	else
		sig = ' ';
	while (flags->width-- > 0)
		ft_printf_putchar(sig);
}

static void	ft_printf_basepnwidth(unsigned long long n, t_flag *flags)
{
	if (flags->hesh == 1 && n)
		flags->width -= 2;
	if (!n)
		flags->width--;
	if (flags->sign == 2)
		flags->width--;
	else if (flags->sign == 1 && flags->p == 2)
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

void		ft_putnbr_pointer(unsigned long n, t_flag flags)
{
	flags.hesh = 1;
	flags.sign = 0;
	if ((!n && flags.accuracy > -1))
		flags.n = 0;
	if (!n && flags.width > 0)
		flags.width -= 2;
	if (flags.width > 0 || flags.accuracy > -1)
		ft_printf_basepnwidth(n, &flags);
	if (flags.p == 1)
		ft_printf_putstr("0x");
	if (flags.p != 2)
		ft_printf_widthnbr(&flags);
	if (flags.p != 1)
		ft_printf_putstr("0x");
	while (flags.accuracy-- > 0)
		ft_printf_putchar('0');
	if (flags.n)
		ft_printf_putbasex(n);
	if (flags.p == 2)
		ft_printf_widthnbr(&flags);
}
