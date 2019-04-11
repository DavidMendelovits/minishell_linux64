/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:37:39 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/13 12:05:37 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*search_dir(char *dir, char *command)
{
	DIR				*dirp;
	struct dirent	*entry;
	char			*path;

	dirp = opendir(dir);
	path = NULL;
	if (!dirp)
	{
//		closedir(dirp);
		return (path);
	}
	while ((entry = readdir(dirp)))
	{
		if (!strcmp(entry->d_name, command))
		{
			path = trip_join(dir, '/', entry->d_name);
		}
	}
	closedir(dirp);
//	if (path)
//		printf("found! -> %s\n", path);
	return (path);
}

char		*search_path_directories(char *command)
{
	int				p;
	char			**path_dirs;
	char			*tmp;
	char			*command_path;

	tmp = replace_char(g_PATH->content, ':', ' ');
	path_dirs = split_stream(tmp);
//	print_strings(path_dirs, 0);
	free(tmp);
	p = 0;
	while (path_dirs[p])
	{
		if ((command_path = search_dir(path_dirs[p], command)))
			break ;
		p += 1;
	}
	free_2d(path_dirs);
	return (command_path);
}

void		search_path(char **argv)
{
	char			*command_path;

	command_path = search_path_directories(argv[0]);
	if (!command_path)
		g_err_num = INVALID;
	if (!command_path)
		b_printf("error\n");
	if (!access(command_path, X_OK))
	{
		execute(command_path, argv);
	}
	else
		g_err_num = INVALID;
	free(command_path);
}
