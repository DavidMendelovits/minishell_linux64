/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:14:46 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 18:34:06 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			skip_whitespaces(char *str, int p)
{
	while (str[p] && (str[p] == ' ' || str[p] == '\t'))
	{
		p += 1;
	}
	return (p);
}

static int			count_words(char *str)
{
	int				word_count;
	int				p;

	p = 0;
	word_count = 0;
	while (str[p])
	{
		if (str[p] == ' ' || str[p] == '\t')
		{
			p = skip_whitespaces(str, p);
		}
		else
		{
			word_count += 1;
			while (str[p] && str[p] != '\t' && str[p] != ' ')
			{
				p += 1;
			}
		}
	}
	return (word_count);
}

char				**ft_strsplit(char *str)
{
	char			**words;
	int				word_count;
	int				begin;
	int				p;
	int				wp;

	word_count = count_words(str);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	p = 0;
	wp = 0;
	while (str[p])
	{
		if (str[p] == ' ' || str[p] == '\t')
			p = skip_whitespaces(str, p);
		else
		{
			begin = p;
			while (str[p] && str[p] != '\t' && str[p] != ' ')
				p += 1;
			words[wp] = ft_strdup_range(str, begin, p - 1);
			wp += 1;
		}
	}
	words[wp] = NULL;
	return (words);
}
