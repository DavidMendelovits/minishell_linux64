/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:16:10 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:17:52 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			i;
	int			len;
	int			div;
	int			p;

	i = 0;
	len = ft_strlen((char *)str);
	div = 1;
	p = len - 1;
	while (p >= 0)
	{
		i += (str[p] - '0') * div;
		div *= 10;
		p -= 1;
	}
	return (i);
}
