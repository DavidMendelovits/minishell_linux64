/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:48:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:28:43 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	int				p;
	int				np;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	new = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	p = 0;
	np = 0;
	while (s1[p])
	{
		new[np] = s1[p];
		p += 1;
		np += 1;
	}
	p = 0;
	while (s2[p])
	{
		new[np] = s2[p];
		np += 1;
		p += 1;
	}
	return (new);
}
