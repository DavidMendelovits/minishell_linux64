/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:56:39 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:19:57 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned		ft_numlen_base(__intmax_t nbr, unsigned int radix)
{
	unsigned int		len;

	len = 0;
	while (nbr)
	{
		nbr /= radix;
		len += 1;
	}
	if (len == 0)
		len = 1;
	return (len);
}

char			*ft_itoa_base(__intmax_t nbr, char *base, unsigned int radix)
{
	unsigned int		num_len;
	char				*str;
	int					is_negative;
	int					sp;
	int					bp;

	is_negative = 0;
	if (nbr < 0)
		is_negative = 1;
	num_len = is_negative + ft_numlen_base(nbr, radix);
	str = (char *)ft_memalloc(sizeof(char) * (num_len + 1));
	sp = num_len - 1;
	while (sp >= 0 && !(sp == 0 && is_negative))
	{
		bp = nbr % radix;
		if (bp < 0)
			bp *= -1;
		str[sp] = base[bp];
		nbr /= radix;
		sp -= 1;
	}
	if (is_negative)
		str[sp] = '-';
	return (str);
}
