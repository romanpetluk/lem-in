/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:05:43 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/15 14:09:58 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printf_s_flag(t_flag *flags)
{
	flags->size = 0;
	flags->width = 0;
	flags->accuracy = -1;
	flags->p = 0;
	flags->sign = 0;
	flags->hesh = 0;
	flags->n = 1;
}

static t_flag	ft_printf_flag(t_flag flags, char c)
{
	if (c == ' ' && flags.sign == 0)
		flags.sign = 1;
	else if (c == '+')
		flags.sign = 2;
	else if (c == '0' && flags.p == 0)
		flags.p = 1;
	else if (c == '-')
		flags.p = 2;
	else if (c == '#')
		flags.hesh = 1;
	return (flags);
}

static t_flag	ft_printf_reint(t_flag flags, const char *format, va_list ap)
{
	if ((format[flags.i] > 47 && format[flags.i] < 58) ||
		format[flags.i] == '*')
		ft_printf_reintwidth(ap, format, &flags);
	if (format[flags.i] == '.')
		ft_printf_reintaccuraty(ap, format, &flags);
	flags.i--;
	return (flags);
}

static t_flag	ft_printf_w(t_flag flags, const char *s, va_list ap)
{
	int			c;

	while ((c = ft_printf_find_flag(s[flags.i], &flags)) != 0)
	{
		if (c == 1 || c == 2)
		{
			ft_printf_typeifsize(flags, s[flags.i], ap);
			flags.i++;
			return (flags);
		}
		if (c == 3)
			flags = ft_printf_size(flags, s[flags.i]);
		else if (c == 4)
			flags = ft_printf_reint(flags, s, ap);
		else if (c == 5)
			flags = ft_printf_flag(flags, s[flags.i]);
		flags.i++;
	}
	if (s[flags.i])
	{
		ft_printf_typeifsize(flags, s[flags.i], ap);
		flags.i++;
	}
	return (flags);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flag		flags;

	va_start(ap, format);
	flags.i = 0;
	g_count = 0;
	while (format[flags.i])
	{
		if (format[flags.i] == '%')
		{
			flags.i++;
			ft_printf_s_flag(&flags);
			flags = ft_printf_w(flags, format, ap);
			if (format[flags.i] == '\0')
				return (g_count);
		}
		else
		{
			ft_printf_putchar(format[flags.i]);
			flags.i++;
		}
	}
	return (g_count);
}
