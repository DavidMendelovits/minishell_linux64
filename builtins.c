/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:27:41 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 11:25:03 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_env(char **args)
{
	if (args && args[1])
	{
		write(2, ARGS, sizeof(ARGS));
		return ;
	}
	print_list(g_env);
}

void		ft_echo(char **args)
{
	if (args && args[1])
		print_args(args, 1);
	b_printf("\n");
}

void		ft_cd(char **args)
{
	int				argc;
	char			buf[PATH_MAX];

	argc = get_pointer_len(args);
	if (argc == 1)
	{
		edit_env("OLDPWD", getcwd(buf, PATH_MAX));
		chdir(search_env("HOME"));
		edit_env("PWD", getcwd(buf, PATH_MAX));
	}
	else if (argc == 2)
	{
		if (!opendir(args[1]))
		{
			g_err_num = CD_ERR;
		}
		else if (!ft_strcmp("-", args[1]))
		{
			//change to oldpwd
		}
		else
		{
			edit_env("OLDPWD", getcwd(buf, PATH_MAX));
			chdir(args[1]);
			edit_env("PWD", getcwd(buf, PATH_MAX));
		}
	}
	else
		g_err_num = CD_ARGS;
	return ;
}

int			is_builtin(char *arg1)
{
//	WOW();
	if (!strcmp(arg1, "echo"))
	{
		return (ECHO);
	}
	else if (!strcmp(arg1, "cd"))
	{
		return (CD);
	}
	else if (!strcmp(arg1, "setenv"))
	{
		return (SETENV);
	}
	else if (!strcmp(arg1, "unsetenv"))
	{
		return (UNSETENV);
	}
	else if (!strcmp(arg1, "env"))
	{
		return (ENV);
	}
	return (0);
}


void		execute_builtin(int command, char **argv)
{
//	WOW();
	if (command == ECHO)
	{
		ft_echo(argv);
	}
	else if (command == CD)
	{
		ft_cd(argv);
	}
	else if (command == SETENV)
	{
		ft_setenv(argv);
	}
	else if (command == UNSETENV)
	{
		ft_unset_env(argv);
	}
	else if (command == ENV)
	{
		ft_env(argv);
	}
}
