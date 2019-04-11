/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:38:57 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:45:20 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

int				dispatch_(va_list arg_list, char spec)
{
	int			printed_chars;

	printed_chars = 0;
	if (spec == 'i' || spec == 'd')
		put_integer(arg_list, &printed_chars);
	else if (spec == 'c')
		put_char(arg_list, &printed_chars);
	else if (spec == 's')
		put_string(arg_list, &printed_chars);
	else if (spec == 'u')
		put_uint(arg_list, &printed_chars);
	else if (spec == 'o')
		put_oct(arg_list, &printed_chars);
	else if (spec == 'x')
		put_hex(arg_list, &printed_chars);
	else if (spec == 'p')
		put_ptr(arg_list, &printed_chars);
	return (printed_chars);
}

char			b_spec_check(const char *format, int *ptr)
{
	int			i;

	i = 0;
	*ptr += 1;
	if (format[*ptr])
	{
		while (i < 8)
		{
			if (SPECS[i] == format[*ptr])
			{
				*ptr += 1;
				return (SPECS[i]);
			}
			i += 1;
		}
	}
	return ('\0');
}

void			put_char(va_list arg_list, int *chars)
{
	char		print;

	print = (char)va_arg(arg_list, int);
	ft_putchar(print);
	*chars += 1;
}

void			put_string(va_list arg_list, int *chars)
{
	char		*print;

	print = va_arg(arg_list, char*);
	ft_putstr(print);
	*chars += 1;
}
