/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:29:16 by rpetluk           #+#    #+#             */
/*   Updated: 2018/02/19 16:45:39 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_printf_unisize(unsigned int b)
{
	int			i;

	i = 1;
	while ((b = b >> 1))
		i++;
	if (i < 8 || MB_CUR_MAX == 1)
		return (1);
	else if (i < 12)
		return (2);
	else if (i < 17)
		return (3);
	else
		return (4);
}

void			ft_printf_unic(unsigned int n, t_flag flags)
{
	if (flags.width < 1)
		ft_make_unicode(n);
	else
	{
		flags.width -= ft_printf_unisize(n);
		if (flags.p != 2)
		{
			ft_printf_width(&flags);
			ft_make_unicode(n);
		}
		else
		{
			ft_make_unicode(n);
			ft_printf_width(&flags);
		}
	}
}

static void		ft_printf_putunisn(wchar_t *s, int k)
{
	int			i;
	int			n;

	i = 0;
	while (s[i] && k >= ft_printf_unisize(s[i]))
	{
		n = ft_printf_unisize(s[i]);
		ft_make_unicode(s[i]);
		i++;
		k -= n;
	}
}

static void		ft_printf_uniwidth(wchar_t *s, t_flag *flags)
{
	int			i;
	int			k;

	k = flags->accuracy;
	i = 0;
	if (flags->accuracy < 0)
		while (s[i])
		{
			flags->width -= ft_printf_unisize(s[i]);
			i++;
		}
	else if (flags->accuracy > -1)
	{
		while (s[i] && k >= ft_printf_unisize(s[i]))
		{
			flags->width -= ft_printf_unisize(s[i]);
			k -= ft_printf_unisize(s[i]);
			i++;
		}
	}
}

void			ft_putstr_uniswidth(wchar_t *s, t_flag flags)
{
	if (s == NULL)
		ft_putstr_width("(null)", flags);
	else
	{
		if (flags.width > 0)
			ft_printf_uniwidth(s, &flags);
		if (flags.p != 2)
			ft_printf_width(&flags);
		if (flags.accuracy < 0)
			ft_printf_unis(s);
		else
			ft_printf_putunisn(s, flags.accuracy);
		if (flags.p == 2)
			ft_printf_width(&flags);
	}
}
