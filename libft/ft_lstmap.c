/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:55:26 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/17 17:58:37 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*ret;

	if (lst && f)
	{
		buf = f(lst);
		ret = buf;
		while (lst->next)
		{
			buf->next = f(lst->next);
			buf = buf->next;
			lst = lst->next;
		}
		return (ret);
	}
	return (NULL);
}
