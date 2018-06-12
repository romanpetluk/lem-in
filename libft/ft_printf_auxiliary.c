/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:28:30 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/15 14:30:38 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_reintwidth(va_list ap, const char *format, t_flag *flags)
{
	int	d;

	flags->width = 0;
	while (format[flags->i] > 47 && format[flags->i] < 58)
	{
		flags->width *= 10;
		flags->width += (format[flags->i] - 48);
		flags->i++;
	}
	while (format[flags->i] == '*')
	{
		d = va_arg(ap, int);
		if (d < 0)
		{
			d *= -1;
			flags->p = 2;
		}
		flags->width = d;
		flags->i++;
	}
}

void	ft_printf_reintaccuraty(va_list ap, const char *format, t_flag *flags)
{
	flags->accuracy = 0;
	while (format[flags->i] == '.')
		flags->i++;
	while (format[flags->i] > 47 && format[flags->i] < 58)
	{
		flags->accuracy *= 10;
		flags->accuracy += (format[flags->i] - 48);
		flags->i++;
	}
	while (format[flags->i] == '*')
	{
		flags->accuracy = va_arg(ap, int);
		flags->i++;
	}
}
