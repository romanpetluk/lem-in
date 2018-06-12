/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:27:09 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/15 15:28:49 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_typeint(t_flag flags, va_list ap)
{
	if (flags.size == 6)
		ft_putnbr_l(va_arg(ap, long long), flags);
	else if (flags.size == 5)
		ft_putnbr_l(va_arg(ap, long int), flags);
	else if (flags.size == 4)
		ft_putnbr_l(va_arg(ap, size_t), flags);
	else if (flags.size == 3)
		ft_putnbr_l(va_arg(ap, intmax_t), flags);
	else if (flags.size == 2)
		ft_putnbr_l((char)va_arg(ap, int), flags);
	else if (flags.size == 1)
		ft_putnbr_l((short)va_arg(ap, int), flags);
}

void		ft_printf_typeunint(t_flag flags, va_list ap)
{
	if (flags.size == 6)
		ft_putnbr_unl(va_arg(ap, unsigned long long), flags);
	else if (flags.size == 5)
		ft_putnbr_unl(va_arg(ap, unsigned long int), flags);
	else if (flags.size == 4)
		ft_putnbr_unl(va_arg(ap, size_t), flags);
	else if (flags.size == 3)
		ft_putnbr_unl(va_arg(ap, uintmax_t), flags);
	else if (flags.size == 2)
		ft_putnbr_unl((unsigned char)va_arg(ap, unsigned int), flags);
	else if (flags.size == 1)
		ft_putnbr_unl((unsigned short)va_arg(ap, unsigned int), flags);
}

void		ft_printf_typebase(t_flag flags, va_list ap)
{
	if (flags.size == 6)
		ft_putnbr_base_width(va_arg(ap, unsigned long long), flags);
	else if (flags.size == 5)
		ft_putnbr_base_width(va_arg(ap, unsigned long int), flags);
	else if (flags.size == 4)
		ft_putnbr_base_width(va_arg(ap, size_t), flags);
	else if (flags.size == 3)
		ft_putnbr_base_width(va_arg(ap, uintmax_t), flags);
	else if (flags.size == 2)
		ft_putnbr_base_width((unsigned char)va_arg(ap, unsigned int), flags);
	else if (flags.size == 1)
		ft_putnbr_base_width((unsigned short)va_arg(ap, unsigned int), flags);
}

void		ft_printf_typebasex(t_flag flags, va_list ap)
{
	if (flags.size == 6)
		ft_putnbr_basex_width(va_arg(ap, unsigned long long), flags);
	else if (flags.size == 5)
		ft_putnbr_basex_width(va_arg(ap, unsigned long int), flags);
	else if (flags.size == 4)
		ft_putnbr_basex_width(va_arg(ap, size_t), flags);
	else if (flags.size == 3)
		ft_putnbr_basex_width(va_arg(ap, uintmax_t), flags);
	else if (flags.size == 2)
		ft_putnbr_basex_width((unsigned char)va_arg(ap, unsigned int), flags);
	else if (flags.size == 1)
		ft_putnbr_basex_width((unsigned short)va_arg(ap, unsigned int), flags);
}

void		ft_printf_typebasexx(t_flag flags, va_list ap)
{
	if (flags.size == 6)
		ft_putnbr_basexx_width(va_arg(ap, unsigned long long), flags);
	else if (flags.size == 5)
		ft_putnbr_basexx_width(va_arg(ap, unsigned long int), flags);
	else if (flags.size == 4)
		ft_putnbr_basexx_width(va_arg(ap, size_t), flags);
	else if (flags.size == 3)
		ft_putnbr_basexx_width(va_arg(ap, uintmax_t), flags);
	else if (flags.size == 2)
		ft_putnbr_basexx_width((unsigned char)va_arg(ap, unsigned int), flags);
	else if (flags.size == 1)
		ft_putnbr_basexx_width((unsigned short)va_arg(ap, unsigned int), flags);
}
