/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:16:53 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:17:38 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				get_num(char c, char *base)
{
	int			i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i += 1;
	}
	return (-1);
}

int						ft_atoi_base(char *int_, char *base)
{
	int			p;
	int			i;
	int			radix;
	int			sign;
	int			place;

	radix = ft_strlen(base);
	p = ft_strlen(int_) - 1;
	i = 0;
	place = 1;
	sign = 1;
	if (int_[0] == '-')
	{
		sign = -1;
	}
	while (p >= 0)
	{
		if (p == 0 && int_[p] == '-')
			break ;
		i += get_num(int_[p], base) * place;
		p -= 1;
		place *= radix;
	}
	return (i * sign);
}
