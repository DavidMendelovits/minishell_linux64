/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:25:10 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:54:44 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_list(t_list *head)
{
	t_list			*traverse;

	traverse = head;
	while (traverse)
	{
		b_printf("%s\n", traverse->content);
		traverse = traverse->next;
	}
}

void		enqueue(t_list **head, char *content)
{
	t_list			*new;
	t_list			*traverse;

	new = malloc(sizeof(*new));
	new->content = ft_strdup(content);
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
	}
	else
	{
		traverse = *head;
		while (traverse && traverse->next)
			traverse = traverse->next;
		traverse->next = new;
	}
	if (!ft_strncmp(new->content, "PATH", 4))
		g_PATH = new;
}

t_list		*copy_extern_env(void)
{
	t_list			*env;
	int				p;

	env = NULL;
	p = 0;
	while (environ[p])
	{
		enqueue(&env, environ[p]);
		p +=1 ;
	}
	return (env);
}

void		init_env(void)
{
	t_list			*env;
	
	env = copy_extern_env();
	g_env = env;
}
