/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:40:52 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:40:30 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count_list(t_list *l)
{
	t_list		*traverse;
	int			p;

	p = 0;
	traverse = l;
	while (traverse)
	{
		p += 1;
		traverse = traverse->next;
	}
	return (p);
}

static char		**copy_env(void)
{
	t_list		*traverse;
	char		**env;
	int			count;
	int			p;

	count = count_list(g_env);
	env = (char **)ft_memalloc(sizeof(*env) * (count + 1));
	p = 0;
	traverse = g_env;
	while (traverse)
	{
		env[p] = ft_strdup(traverse->content);
		p += 1;
		traverse = traverse->next;
	}
	env[p] = NULL;
	return (env);
}

void 			execute(char *path, char **argv)
{
	int			pid;
	int			status;
	char		**env;

	env = copy_env();
	pid = fork();
	if (pid == 0)
	{
		execve(path, argv, env);
		_exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		status = -1;
	}
	else
	{
		if (waitpid(pid, &status, 0) != pid)
		{
			status = 1;
		}
		free_2d(env);
		return ;
	}
}
