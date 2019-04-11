/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:34:31 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:35:36 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned		ft_unumlen_base(__uintmax_t nbr, unsigned int radix)
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

char				*ft_utoa_base(__uintmax_t nbr, char *base, unsigned int radix)
{
	unsigned int		num_len;
	char				*str;
	int					sp;

	num_len = 0;
	num_len += ft_unumlen_base(nbr, radix);
	str = (char *)ft_memalloc(sizeof(char) * (num_len + 1));
	sp = num_len - 1;
	while (sp >= 0)
	{
		str[sp] = base[nbr % radix];
		nbr /= radix;
		sp -= 1;
	}
	return (str);
}
