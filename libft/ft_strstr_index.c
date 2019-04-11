/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:53:42 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:31:20 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strstr_index(const char *haystack, const char *needle)
{
	int				hp;
	int				np;
	int				start;

	hp = 0;
	np = 0;
	if (!needle)
		return (0);
	while (haystack[hp] && haystack[hp] != needle[np])
		hp += 1;
	if (!haystack[hp])
		return (-1);
	start = hp;
	while (haystack[hp] == needle[np])
	{
		hp += 1;
		np += 1;
	}
	if (!needle[np])
		return (start);
	return (-1);
}
