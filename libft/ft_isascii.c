/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:40:09 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/05 15:12:36 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	else
		return (0);
}