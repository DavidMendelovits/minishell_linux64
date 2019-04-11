/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:34:11 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:54:14 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*search_env(char *name)
{
	t_list			*traverse;

	traverse = g_env;
	while (traverse)
	{
		if (!ft_strncmp(name, traverse->content, ft_strlen(name)))
		{
			return (ft_strdup_range(traverse->content,
					ft_strchr_index(traverse->content, '=') + 1,
					ft_strlen(traverse->content)));
		}
		traverse = traverse->next;
	}
	return (NULL);
}

void		edit_env(char *name, char *value)
{
	t_list			*traverse;
	char			*new;
	int				overwrite;

	new = NULL;
	traverse = g_env;
	overwrite = 0;
	while (traverse)
	{
		if (!ft_strncmp(name, traverse->content, ft_strlen(name) - 1))
		{
			new = trip_join(name, '=', value);
			free(traverse->content);
			traverse->content = ft_strdup(new);
			free(new);
			if (!ft_strcmp(name, "PATH"))
				g_PATH = traverse;
			overwrite = 1;
		}
		traverse = traverse->next;
	}
	if (!overwrite)
	{
		new = trip_join(name, '=', value);
		enqueue(&g_env, new);
		free(new);
	}
}

void		ft_setenv(char **argv)
{
	int				argc;

	argc = get_pointer_len(argv);
	if (argc == 1)
	{
		ft_env(NULL);
	}
	else if (argc == 2)
	{
		edit_env(argv[1], (NULL));
	}
	else if (argc == 3)
	{
		edit_env(argv[1], argv[2]);
	}
	else
	{
		g_err_num = SETENV_ARGS;
	}
}

void		ft_remove_env_var(t_list **env_head, char *name)
{
//	WOW();
	t_list			*traverse;
	t_list			*lag;

	traverse = *env_head;
	if (traverse && !ft_strncmp(traverse->content, name, ft_strlen(name)))
	{
		*env_head = traverse->next;
		free(traverse->content);
		free(traverse);
		return ;
	}
	while (traverse && ft_strncmp(traverse->content, name, ft_strlen(name)))
	{
		lag = traverse;
		traverse = traverse->next;
	}
	if (!traverse)
		return ;
	lag->next = traverse->next;
	free(traverse->content);
	free(traverse);
}

void		ft_unset_env(char **args)
{
//	WOW();
	int				argc;

	argc = get_pointer_len(args);
	if (argc == 1)
	{
		g_err_num = UNSETENV_ARGS;
	}
	else if (argc > 2)
	{
		return ;
	}
	else
		ft_remove_env_var(&g_env, args[1]);
}
