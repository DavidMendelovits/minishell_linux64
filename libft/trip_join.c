/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trip_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:55:47 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:32:36 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*trip_join(const char *s1, const char c, const char *s2)
{
	char			*new;
	int				tmp;
	int				p;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	tmp = 0;
	p = 0;
	if (s1)
	{
		while (s1[tmp])
			new[p++] = s1[tmp++];
	}
	if (c)
		new[p++] = c;
	tmp = 0;
	if (s2)
	{
		while (s2[tmp])
			new[p++] = s2[tmp++];
	}
	new[p] = '\0';
	return (new);
}
