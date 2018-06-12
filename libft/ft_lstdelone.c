/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:57:48 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/17 10:57:49 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (alst && *alst && del)
	{
		buf = *alst;
		(del)(buf->content, buf->content_size);
		free(buf);
		*alst = NULL;
	}
}
