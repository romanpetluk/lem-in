/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unimask.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:38:15 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/19 16:51:03 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_bit_size(unsigned int b)
{
	int			i;

	i = 1;
	while ((b = b >> 1))
		i++;
	return (i);
}

static void			ft_printf_mask1(unsigned int b)
{
	unsigned char	uni_char;
	unsigned int	mask1;

	mask1 = 0xC080;
	uni_char = (b >> 6) | (mask1 >> 8);
	ft_printf_putchar(uni_char);
	uni_char = ((b << 26) >> 26) | mask1;
	ft_printf_putchar(uni_char);
}

static void			ft_printf_mask2(unsigned int b)
{
	unsigned char	uni_char;
	unsigned int	mask2;

	mask2 = 0xE08080;
	uni_char = (b >> 12) | (mask2 >> 16);
	ft_printf_putchar(uni_char);
	uni_char = (((b >> 6) << 26) >> 26) | ((mask2 << 16) >> 24);
	ft_printf_putchar(uni_char);
	uni_char = ((b << 26) >> 26) | ((mask2 << 24) >> 24);
	ft_printf_putchar(uni_char);
}

static void			ft_printf_mask3(unsigned int b)
{
	unsigned char	uni_char;
	unsigned int	mask3;

	mask3 = 0xF0808080;
	uni_char = (b >> 18) | (mask3 >> 24);
	ft_printf_putchar(uni_char);
	uni_char = (((b >> 12) << 26) >> 26) | ((mask3 << 8) >> 24);
	ft_printf_putchar(uni_char);
	uni_char = (((b >> 6) << 26) >> 26) | ((mask3 << 16) >> 24);
	ft_printf_putchar(uni_char);
	uni_char = ((b << 26) >> 26) | ((mask3 << 24) >> 24);
	ft_printf_putchar(uni_char);
}

void				ft_make_unicode(unsigned int b)
{
	unsigned char	uni_char;
	int				len_bits;

	len_bits = ft_bit_size(b);
	if (len_bits <= 7 || MB_CUR_MAX < 2)
	{
		uni_char = b;
		ft_printf_putchar(uni_char);
	}
	else if (len_bits <= 11 || MB_CUR_MAX < 3)
		ft_printf_mask1(b);
	else if (len_bits <= 16 || MB_CUR_MAX < 4)
		ft_printf_mask2(b);
	else
		ft_printf_mask3(b);
}
