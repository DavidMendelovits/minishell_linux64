/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:26:26 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:27:12 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strdup(const char *str)
{
	char				*dup;
	int					str_len;
	int					p;

	str_len = ft_strlen(str);
	p = 0;
	dup = malloc(sizeof(char) * (str_len + 1));
	while (p < str_len)
	{
		dup[p] = str[p];
		p += 1;
	}
	dup[p] = '\0';
	return (dup);
}
