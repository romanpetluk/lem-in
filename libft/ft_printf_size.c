/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:21:31 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/20 09:45:24 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flag		ft_printf_size(t_flag flags, char c)
{
	if (c == 'l')
	{
		if (flags.size < 5)
			flags.size = 5;
		else if (flags.size == 5)
			flags.size = 6;
	}
	else if (c == 'j' && flags.size < 3)
		flags.size = 3;
	else if (c == 'z' && flags.size < 4)
		flags.size = 4;
	else if (c == 'h')
	{
		if (flags.size == 0)
			flags.size = 1;
		else if (flags.size == 1)
			flags.size = 2;
		else if (flags.size == 2)
			flags.size = 1;
	}
	return (flags);
}

static void	ft_printf_typesize00(t_flag flags, char c, va_list ap)
{
	if (c == 'o')
		ft_putnbr_base_width(va_arg(ap, unsigned int), flags);
	else if (c == 'O')
		ft_putnbr_base_width(va_arg(ap, unsigned long int), flags);
	else if (c == 'x')
		ft_putnbr_basex_width(va_arg(ap, unsigned int), flags);
	else if (c == 'X')
		ft_putnbr_basexx_width(va_arg(ap, unsigned int), flags);
	else if (c == 'p')
		ft_putnbr_pointer(va_arg(ap, unsigned long int), flags);
	else
		ft_putchar_width(c, flags);
}

static void	ft_printf_typesize0(t_flag flags, char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_width((char)va_arg(ap, int), flags);
	else if (c == 's')
		ft_putstr_width(va_arg(ap, char *), flags);
	else if (c == 'u')
		ft_putnbr_l(va_arg(ap, unsigned int), flags);
	else if (c == 'U')
		ft_putnbr_l(va_arg(ap, unsigned long int), flags);
	else if (c == 'd' || c == 'i')
		ft_putnbr_l(va_arg(ap, int), flags);
	else if (c == 'D')
		ft_putnbr_l(va_arg(ap, long int), flags);
	else if (c == 'C')
		ft_printf_unic(va_arg(ap, unsigned int), flags);
	else if (c == 'S')
		ft_putstr_uniswidth(va_arg(ap, wchar_t *), flags);
	else
		ft_printf_typesize00(flags, c, ap);
}

static void	ft_printf_typechar(t_flag flags, va_list ap)
{
	if (flags.size == 6)
		ft_putnbr_l(va_arg(ap, long long), flags);
	else if (flags.size == 5)
		ft_printf_unic(va_arg(ap, unsigned int), flags);
	else if (flags.size == 4)
		ft_putnbr_l(va_arg(ap, size_t), flags);
	else if (flags.size == 3)
		ft_putnbr_l(va_arg(ap, intmax_t), flags);
	else if (flags.size == 2)
		ft_putnbr_l((char)va_arg(ap, int), flags);
	else if (flags.size == 1)
		ft_putnbr_l((short)va_arg(ap, int), flags);
}

void		ft_printf_typeifsize(t_flag flags, char c, va_list ap)
{
	if ((c == 'D' && flags.size < 5) ||
		(c == 'U' && flags.size < 5) || (c == 'O' && flags.size < 5))
		flags.size = 5;
	if (flags.size == 0 || c == 'p')
		ft_printf_typesize0(flags, c, ap);
	else if (c == 'd' || c == 'D' || c == 'i')
		ft_printf_typeint(flags, ap);
	else if (c == 's')
		ft_printf_typechars(ap, flags);
	else if (c == 'c')
		ft_printf_typechar(flags, ap);
	else if (c == 'C')
		ft_printf_unic(va_arg(ap, unsigned int), flags);
	else if (c == 'S')
		ft_putstr_uniswidth(va_arg(ap, wchar_t *), flags);
	else if (c == 'u' || c == 'U')
		ft_printf_typeunint(flags, ap);
	else if (c == 'o' || c == 'O')
		ft_printf_typebase(flags, ap);
	else if (c == 'x')
		ft_printf_typebasex(flags, ap);
	else if (c == 'X')
		ft_printf_typebasexx(flags, ap);
	else
		ft_putchar_width(c, flags);
}
