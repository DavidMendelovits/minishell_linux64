/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:06:36 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:51:26 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

# define BUFF_SIZE 48

typedef struct	s_rolodex
{
	char				*content;
	int					fd;
	struct s_rolodex	*next;
}				t_rolodex;

int				get_next_line(const int fd, char **line);
#endif
