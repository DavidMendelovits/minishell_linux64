/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:09:38 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 11:27:02 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count_args(char *s)
{
	int				p;
	int				count;

	p = 0;
	count = 0;
	while (s[p])
	{
		if (s[p] == ' ' || s[p] == '\t')
		{
			while (s[p] && (s[p] == ' ' || s[p] == '\t'))
				p += 1;
		}
		else if (s[p] == '"')
		{
			count += 1;
			p += 1;
			while (s[p] && s[p] != '"')
				p += 1;
			p += 1;
		}
		else
		{
			count += 1;
			while (s[p] && s[p] != ' ' && s[p] != '\t')
				p += 1;
		}
	}
	return (count);
}

int			expand(char **new, char *var, int p)
{
	*new = search_env(var);
	return (p);
}

void		expand_tilde(char **tilde)
{
	char			*tmp;
	char			*new;
	int				p;

	if (!strncmp(*tilde, "~+", 2))
		p = expand(&new, "PWD", 2);
	else if (!strncmp(*tilde, "~-", 2))
		p = expand(&new, "OLDPWD", 2);
	else
		p = expand(&new, "HOME", 1);
	if (!(*tilde)[p])
	{
		free(*tilde);
		*tilde = new;
	}
	else if ((int)strlen(*tilde) > p && (*tilde)[p] == '/')
	{
		tmp = ft_strdup_range(*tilde, ft_strchr_index(*tilde, '/'), strlen(*tilde) - 1);
		free(*tilde);
		*tilde = trip_join(new, 0, tmp);
		free(new);
		free(tmp);
	}
	else
		free(new);
}

char		*pull_literal(char *s, int *p)
{
	int				begin;
	char			*string;

	begin = ++(*p);
	string = NULL;
	while (s[*p] && s[*p] != '"')
	{
		*p += 1;
	}
	if (!s[*p])
	{
		g_err_num = PAREN;
		return (NULL);
	}
	string = ft_strdup_range(s, begin, *p - 1);
	*p += 1;
	return (string);
}

char		*pull_word(char *s, int *p)
{
	int				begin;
	char			*word;

	begin = *p;
	word = NULL;
	while (s[*p] && s[*p] != ' ' && s[*p] != '\t')
	{
		*p += 1;
	}
	word = ft_strdup_range(s, begin, *p - 1);
	return (word);
}

int			skip_whitespace(char *s, int p)
{
	while (s[p] && (s[p] == ' ' || s[p] == '\t'))
	{
		p += 1;
	}
	return (p);
}

char		**allocate_arguments(char *s)
{
	char			**strings;
	int				arg_count;

	arg_count = count_args(s);
	strings = (char **)ft_memalloc(sizeof(*strings) * (arg_count + 1));
	return (strings);
}

void		expand_dollar_sign(char **s)
{
	char			*tmp;
	char			*new;

	if (!(*s)[1])
		return ;
	tmp = ft_strdup_range(*s, 1, ft_strlen(*s));
	expand(&new, tmp, 0);
	free(tmp);
	if (new)
	{
		free(*s);
		*s = new;
	}
}

void		expand_variable(char **s)
{
	if ((*s)[0] == '~')
		expand_tilde(s);
	else if ((*s)[0] == '$')
		expand_dollar_sign(s);
}

char		**split_stream(char *s)
{
	char			**strings;
	int				p;
	int				sp;

	strings = allocate_arguments(s);
	p = 0;
	sp = 0;
	while (s[p])
	{
		if (s[p] == ' ' || s[p] == '\t')
			p = skip_whitespace(s, p);
		else if (s[p] == '"')
		{
			if (!(strings[sp++] = pull_literal(s, &p)))
				return (NULL);
		}
		else
		{
			strings[sp] = pull_word(s, &p);
			if (strings[sp][0] == '~' || strings[sp][0] == '$')
				expand_variable(&strings[sp]);
			sp += 1;
		}
	}
	return (strings);
}
