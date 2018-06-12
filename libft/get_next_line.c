/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:38:36 by rpetluk           #+#    #+#             */
/*   Updated: 2018/06/02 13:38:39 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*read_from_buff(char **buff)
{
	char		*readed;
	char		*tmp;
	size_t		buff_len;
	size_t		rp;

	readed = NULL;
	rp = 0;
	buff_len = ft_strlen(*buff);
	if ((tmp = ft_strchr(*buff, '\n')))
	{
		rp = tmp - *buff;
		readed = ft_strsub(*buff, 0, rp);
		tmp = *buff;
		*buff = ft_strsub(*buff, rp + 1, buff_len - rp - 1);
		ft_strdel(&tmp);
	}
	return (readed);
}

t_stream	*get_stream(t_list **streams, int fd)
{
	t_list		*runner;
	t_stream	*stream;

	stream = NULL;
	runner = *streams;
	while (runner)
	{
		if (((t_stream*)(runner->content))->fd == fd)
		{
			stream = runner->content;
			return (stream);
		}
		runner = runner->next;
	}
	if (!stream)
	{
		stream = (t_stream*)malloc(sizeof(t_stream));
		stream->fd = fd;
		stream->buff = ft_strnew(0);
		ft_lstadd(streams, ft_lstnew(stream, sizeof(t_stream)));
		free(stream);
		stream = (*streams)->content;
	}
	return (stream);
}

int			read_from_file(char **buff, int fd)
{
	int		readed;
	char	*rd;
	char	*tmp;
	int		rt;

	rd = ft_strnew(BUFF_SIZE);
	if ((readed = read(fd, rd, BUFF_SIZE)) > 0)
	{
		rt = (readed != BUFF_SIZE) ? 0 : 1;
		if (!rt)
		{
			tmp = rd;
			rd = ft_strsub(rd, 0, readed);
			ft_strdel(&tmp);
		}
		tmp = *buff;
		*buff = ft_strjoin(*buff, rd);
		ft_strdel(&tmp);
	}
	ft_strdel(&rd);
	return (readed > 0 ? rt : readed);
}

void		lst_del_node(t_list **lst, t_stream *cnt)
{
	t_list *tmp;
	t_list *runner;

	if (((t_stream*)((*lst)->content)) == cnt)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(cnt->buff);
		free(cnt);
		free(tmp);
		return ;
	}
	runner = *lst;
	while ((t_stream*)(runner->next->content) != cnt)
		runner = runner->next;
	tmp = runner->next;
	runner->next = runner->next->next;
	free(((t_stream*)tmp->content)->buff);
	free(tmp->content);
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*streams;
	t_stream		*stream;
	int				rv;
	char			*res;

	rv = 1;
	stream = get_stream(&streams, fd);
	while (rv > 0 && !(res = read_from_buff(&(stream->buff))))
		rv = read_from_file(&(stream->buff), fd);
	if (rv <= 0)
	{
		if ((res = read_from_buff(&(stream->buff))))
			rv = 1;
		else if (!ft_strlen(stream->buff) || rv < 0)
			lst_del_node(&streams, stream);
		else
		{
			rv = 1;
			res = ft_strdup(stream->buff);
			lst_del_node(&streams, stream);
		}
	}
	if (rv > 0)
		*line = res;
	return (rv);
}
