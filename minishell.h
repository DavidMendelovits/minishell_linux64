/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:42:38 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:38:38 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <strings.h>
# include <string.h>
# include <assert.h>
# include "libft/libft.h"

# define WOW() printf("->%s\n", __func__)

extern char	**environ;

typedef struct 		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list		*g_PATH;
t_list		*g_env;


typedef enum
{
	ZERO,
	ECHO,
	CD,
	SETENV,
	UNSETENV,
	ENV
}		t_builtins;

unsigned int g_err_num;

typedef enum
{
	CLEAN,
	PAREN,
	INVALID,
	CD_ERR,
	SETENV_ERR,
	ARG_ERR,
	SETENV_INVAL,
	SETENV_ARGS,
	UNSETENV_ARGS,
	CD_ARGS
}		t_errors;

//#define PATH_MAX 1024
#define INVALID_P "Error! -> Invalid Parameteres\n"
#define MISSING_P "Error! -> missing parenthesis\n"
#define INVALID_COMMAND "Error! -> Invalid Command\n"
#define CD_NOTINPWD "cd: string not in pwd: "
#define INVALID_DIR "cd: no such file or directory: "
#define CD_TOOMANYARGS "cd: too many arguments\n"
#define ARGS "Error! -> invalid number of arguments\n"
#define NULL_ARG "Error -> can't take empty argument\n"
#define UNSETENV_ARGS_ERR "unsetenv: Too few arguments.\n"
#define SETENV_ARGS_ERR "setenv: Too many arguments.\n"

void			*write_error(char *err, size_t size);
void			print_error(void);
void			print_list(t_list *head);

void			enqueue(t_list **head, char *content);

char			*replace_char(char *s, int old, int new);
int				get_pointer_len(char **env);
void			free_2d(char **ptrs);

void			init_env(void);

int				count_args(char *s);
char			*search_env(char *name);

void			read_line(void);

void			parse_input(char *input);
void			expand_tilde(char **tilde);
char			**split_stream(char *s);

void			execute(char *path, char **argv);
int				is_builtin(char *arg1);
void			execute_builtin(int command, char **argv);

void			ft_echo(char **args);
void			ft_cd(char **args);

void			ft_setenv(char **argv);
void			edit_env(char *name, char *value);
void			ft_remove_env_var(t_list **env_head, char *name);
void			ft_unset_env(char **args);
void			ft_env(char **args);

char			*search_dir(char *dir, char *command);
void			search_path(char **argv);
char			*search_path_directories(char *command);

void			print_args(char **strings, int p);
void			print_strings(char **strings, int p);
#endif
