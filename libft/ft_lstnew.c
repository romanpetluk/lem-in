/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:54:51 by rpetluk           #+#    #+#             */
/*   Updated: 2017/11/17 10:54:53 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ret->content_size = content ? content_size : 0;
	ret->content = NULL;
	ret->next = NULL;
	if (content && (ret->content = malloc(content_size)))
		ft_memcpy(ret->content, content, content_size);
	return (ret);
}
