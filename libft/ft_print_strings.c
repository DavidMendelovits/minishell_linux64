/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:22:26 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:23:18 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_strings(char **strings)
{
	int			p;

	p = 0;
	while (strings[p])
	{
		ft_putstr(strings[p]);
		write(1, "\n", 1);
		p += 1;
	}
}
