/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:20:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:21:03 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memalloc(size_t size)
{
	void				*mem;

	if ((mem = malloc(size)))
	{
		ft_bzero(mem, size);
	}
	return (mem);
}
