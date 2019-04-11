/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:23:56 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 11:28:30 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_line(void)
{
	char			buffer[1024];
	int				p;
	char			*input;

	p = 0;
	bzero(buffer, 1024);
	write(1, "?>", 2);
	while (read(0, &buffer[p], 1))
	{
		if (buffer[p] == '\n')
		{
			buffer[p] = '\0';
			break ;
		}
		p += 1;
	}
	if (p > 0)
	{
		if (!ft_strncmp(buffer, "quit", 4) || !ft_strncmp(buffer, "exit", 4))
			return ;
		input = ft_strdup(buffer);
		parse_input(input);
		free(input);
	}
	read_line();
}

void		parse_input(char *input)
{
	char			**args;
	int				command;

	args = split_stream(input);
	if (!args)
	{
		write_error(MISSING_P, sizeof(MISSING_P));
		return ;
	}
	if (!access(args[0], X_OK))
 		execute(args[0], args);
	else if ((command = is_builtin(args[0])))
	{
		execute_builtin(command, args);
	}
	else
	{
		search_path(args);
	}
	free_2d(args);
}
