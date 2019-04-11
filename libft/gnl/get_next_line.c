/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:09:28 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:51:51 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				rolodex_add_front(t_rolodex **head, t_rolodex *new)
{
	if (!(*head))
	{
		*head = new;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
}

static t_rolodex	*search_rolodex(t_rolodex **rolodex, int fd)
{
	t_rolodex			*tmp;

	tmp = *rolodex;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_rolodex *)malloc(sizeof(t_rolodex));
	tmp->content = ft_strnew(1);
	tmp->fd = fd;
	tmp->next = NULL;
	rolodex_add_front(rolodex, tmp);
	tmp = *rolodex;
	return (tmp);
}

char				*get_line(char **content)
{
	char				*overflow;
	char				*line;
	int					len;
	int					newline;

	newline = ft_strchr_index(*content, '\n');
	len = ft_strlen(*content);
	if (newline)
		line = ft_strdup_range(*content, 0, newline - 1);
	else
		line = ft_strnew(1);
	if (newline < len)
	{
		overflow = ft_strdup_range(*content, newline + 1, len - 1);
		free(*content);
		*content = overflow;
	}
	else
		free(*content);
	return (line);
}

void				free_join(char **a, char *b)
{
	char				*tmp;

	tmp = trip_join(*a, 0, b);
	free(*a);
	*a = tmp;
}

int					get_next_line(const int fd, char **line)
{
	char				buffer[BUFF_SIZE + 1];
	t_rolodex			*current;
	static t_rolodex	*rolodex;
	int					p;
	int					ret;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	current = search_rolodex(&rolodex, fd);
	p = 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		free_join(&current->content, buffer);
		if (((p = ft_strchr_index(current->content, '\n'))
		|| current->content[0] == '\n'))
			break ;
	}
	if ((p || current->content))
		*line = get_line(&current->content);
	if (ret < BUFF_SIZE && !ft_strlen(current->content) && !(*line))
		return (0);
	return (1);
}
