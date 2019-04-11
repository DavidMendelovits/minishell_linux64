/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:27:16 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:28:08 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup_range(const char *str, int begin, int end)
{
	char			*duplicate;
	int				dp;
	int				sp;

	if (begin > end)
		return (NULL);
	duplicate = (char*)ft_memalloc(sizeof(char) * (end - begin + 2));
	sp = begin;
	dp = 0;
	while (sp <= end)
	{
		duplicate[dp] = str[sp];
		dp += 1;
		sp += 1;
	}
	duplicate[dp] = '\0';
	return (duplicate);
}
