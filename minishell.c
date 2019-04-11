/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:47:07 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 11:25:50 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*replace_char(char *s, int old, int new)
{
	char			*ret;
	int				p;

	ret = ft_strdup(s);
	p = 0;
	while (s[p])
	{
		if (s[p] == old)
		{
			ret[p] = new;
		}
		p += 1;
	}
	return (ret);
}

int			get_pointer_len(char **env)
{
	int				p;

	p = 0;
	while (env[p])
	{
		p += 1;
	}
	return (p);
}

void		free_2d(char **ptrs)
{
	int				p;
	int				len;

	len = get_pointer_len(ptrs);
	p = 0;
	while (ptrs[p] && p < len)
	{
		if (ptrs[p])
			free(ptrs[p]);
		p += 1;
	}
	free(ptrs);
}

void		free_env(void)
{
	t_list			*tmp;

	while (g_env)
	{
		tmp = g_env;
		g_env = g_env->next;
		free(tmp->content);
		free(tmp);
	}
}

int			main(void)
{
	DIR				*dirp;
//	struct dirent 	*entry;

	dirp = opendir(".");
//	entry = readdir(dirp);
	init_env();
	read_line();
	free_env();
	free(dirp);
	return (0);
}
