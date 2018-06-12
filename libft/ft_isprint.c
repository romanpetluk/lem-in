/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:51:45 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/05 15:52:03 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	else
		return (0);
}
