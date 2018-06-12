/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:18:16 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/15 15:21:14 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_width(t_flag *flags)
{
	char	sig;

	if (flags->p != 1)
		sig = ' ';
	else
		sig = '0';
	while (flags->width-- > 0)
		ft_printf_putchar(sig);
}

void		ft_putchar_width(char c, t_flag flags)
{
	if (flags.width == 0)
		ft_printf_putchar(c);
	else
	{
		flags.width--;
		if (flags.p != 2)
		{
			ft_printf_width(&flags);
			ft_printf_putchar(c);
		}
		else
		{
			ft_printf_putchar(c);
			ft_printf_width(&flags);
		}
	}
}

static void	ft_printf_strnwidth(char *s, t_flag *flags)
{
	int		i;

	i = 0;
	if (flags->accuracy < 0)
		while (s[i])
		{
			flags->width--;
			i++;
		}
	else if (flags->accuracy > -1)
	{
		while (s[i] && i < flags->accuracy)
		{
			flags->width--;
			i++;
		}
	}
}

void		ft_putstr_width(char *s, t_flag flags)
{
	if (s == NULL)
		s = "(null)";
	if (flags.width > 0)
		ft_printf_strnwidth(s, &flags);
	if (flags.p != 2)
		ft_printf_width(&flags);
	if (flags.accuracy < 0)
		ft_printf_putstr(s);
	else
		ft_printf_putstrn(s, flags.accuracy);
	if (flags.p == 2)
		ft_printf_width(&flags);
}

void		ft_printf_typechars(va_list ap, t_flag flags)
{
	if (flags.size == 5)
		ft_putstr_uniswidth(va_arg(ap, wchar_t *), flags);
	else
		ft_putstr_width(va_arg(ap, char *), flags);
}
