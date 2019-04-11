/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:22:02 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:33:53 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*ptr;

	ptr = s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr += 1;
	}
	return (s);
}
