/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:10:40 by rpetluk           #+#    #+#             */
/*   Updated: 2018/07/21 16:11:11 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

static void	remove_link(t_move *pre, t_move *deleted, t_move **move)
{
	if (pre)
		pre->next = deleted->next;
	else
		*move = deleted->next;
	free (deleted);
	deleted = NULL;
}

int			remove_start_finish(t_rooms *room, t_move **move)
{
	t_move	*temp;
	t_move	*t;

	temp = *move;
	while (temp)
	{
		if (temp->name == room->name && temp->name_next == room->prev->name)
		{
			remove_link(t, temp, move);
			return (1);
		}
		else if (temp->name == room->prev->name && temp->name_next == room->name)
		{
			remove_link(t, temp, move);
			return (1);
		}
		t = temp;
		temp = temp->next;
	}
	return (0);
}
