/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:13:17 by rpetluk           #+#    #+#             */
/*   Updated: 2017/12/17 17:13:20 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_njoin(char *string, char *re)
{
	int				i;
	int				l;
	char			*j;

	j = (char *)malloc(sizeof(char) * (ft_strlen(string) + ft_strlen(re) + 1));
	i = 0;
	l = 0;
	while (string && string[i])
	{
		j[i] = string[i];
		i++;
	}
	if (string)
		free(string);
	while (re[l] && re[l] != '\n')
		j[i++] = re[l++];
	j[i] = '\0';
	if (re[l] == '\0')
		re[0] = '\0';
	i = 0;
	if (re[l++] == '\n')
		while (re[l])
			re[i++] = re[l++];
	re[i] = '\0';
	return (j);
}

static char			*ft_re(int len, char *re, char **line)
{
	char			*string;
	int				l;
	int				i;

	i = 0;
	l = 0;
	string = (char *)malloc(sizeof(char) * (len + 1));
	while (re[i] && re[i] != '\n')
	{
		string[i] = re[i];
		i++;
	}
	string[i] = '\0';
	if (re[i++] == '\n')
	{
		while (re[i] && re[i] != '\0')
			re[l++] = re[i++];
		re[l] = '\0';
		*line = string;
		return (NULL);
	}
	re[l] = '\0';
	return (string);
}

static int			ft_read(const int fd, char **line, char *re, int i)
{
	char			*string;
	int				error;

	if (!(string = ft_re(ft_strlen(re), re, line)))
		return (1);
	while (0 < (error = read(fd, re, BUFF_SIZE)))
	{
		re[error] = '\0';
		i = 0;
		while (re[i])
			if (re[i++] == '\n')
			{
				string = ft_njoin(string, re);
				*line = string;
				return (1);
			}
		string = ft_njoin(string, re);
	}
	if (string[0] != '\0')
	{
		*line = string;
		return (1);
	}
	free(string);
	return (error);
}

static t_list		*if_fd(t_list **file_fd, int fd)
{
	t_list			*temp;

	temp = *file_fd;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 0);
	temp->content_size = fd;
	free(temp->content);
	temp->content = (t_list*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_lstadd(file_fd, temp);
	temp = *file_fd;
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	int				error;
	static t_list	*file_fd;
	t_list			*temp;

	if (BUFF_SIZE < 1 || read(fd, NULL, 0) || line == NULL)
		return (-1);
	temp = if_fd(&file_fd, fd);
	error = ft_read(temp->content_size, line, temp->content, 0);
	return (error);
}
