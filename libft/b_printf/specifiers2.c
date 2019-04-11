/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:45:33 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/18 13:11:12 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void			put_integer(va_list arg_list, int *chars)
{
	int				int_;

	int_ = va_arg(arg_list, int);
	if (int_ < 0)
	{
		ft_putchar('-');
		int_ *= -1;
		*chars += 1;
	}
	putnbr_base(int_, 10, chars);
}

void			put_uint(va_list arg_list, int *chars)
{
	unsigned int	uint_;

	uint_ = va_arg(arg_list, unsigned int);
	putnbr_base(uint_, 10, chars);
}

void			put_oct(va_list arg_list, int *chars)
{
	int				oct_;

	oct_ = va_arg(arg_list, int);
	putnbr_base(oct_, 8, chars);
}

void			put_hex(va_list arg_list, int *chars)
{
	unsigned int	hex_;

	hex_ = va_arg(arg_list, unsigned int);
	putnbr_base(hex_, 16, chars);
}

void			put_ptr(va_list arg_list, int *chars)
{
	unsigned long	ptr_;

	ptr_ = va_arg(arg_list, unsigned long);
	write(1, "0x", 2);
	*chars += 2;
	putnbr_base(ptr_, 16, chars);
}
