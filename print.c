/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:38:47 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/13 12:08:49 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			print_args(char **strings, int p)
{
	if (!strings)
		return ;
	if (strings[p])
	{
		b_printf("%s ", strings[p]);
	}
	if (strings[p + 1])
	{
		print_args(strings, p + 1);
	}
}

void			print_strings(char **strings, int p)
{
	if (!strings)
		return ;
	if (strings[p])
	{
		printf("%s\n", strings[p]);
	}
	if (strings[p + 1])
	{
		print_strings(strings, p + 1);
	}
}


void			*write_error(char *err, size_t size)
{
	write(2, err, size);
	return (NULL);
}

void		print_error(void)
{
	if (g_err_num == SETENV_INVAL)
		write_error(ARGS, sizeof(ARGS));
	else if (g_err_num == CD_ERR)
		return ;		
	else if (g_err_num == INVALID)
		write_error(INVALID_COMMAND, sizeof(INVALID_COMMAND));
	else if (g_err_num == SETENV_ERR)
		write_error(NULL_ARG, sizeof(NULL_ARG));
}
