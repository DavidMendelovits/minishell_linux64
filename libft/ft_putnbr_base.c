/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:23:43 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:24:20 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define NUM "01234567890abcdef"

void			ft_putnbr_base(unsigned long long number, int base)
{
	if (number >= (unsigned long)base)
	{
		ft_putnbr_base(number / (unsigned long long)base, base);
	}
	if (number > (unsigned long)base && base > 10)
	{
		ft_putchar(NUM[number % base + 10]);
	}
	else
	{
		ft_putchar(NUM[number % base]);
	}
}
