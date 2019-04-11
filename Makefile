# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 09:03:30 by dmendelo          #+#    #+#              #
#    Updated: 2018/11/15 09:40:39 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror

ASAN = -g -fsanitize=address

SRC = minishell.c prompt.c init.c builtins.c env.c parse_input.c path.c print.c \
	  fork.c

OBJ = minishell.o prompt.o init.o builtins.o env.o parse_input.o path.o print.o \
	  fork.o

LIBFT = libft/libft.a

INC = -I . -I libft

all: $(OBJ)
		@make -C libft
		@gcc -c $(SRC) $(CFLAGS) -g $(INC)
		@gcc $(OBJ) $(CFLAGS) -g $(LIBFT) -o $(NAME)
		@echo "compiled!"

clean:
		@make -C libft clean
		@rm -rf $(OBJ)
		@echo "CLEEAN"

fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
		@echo "executable D E S T R O Y E D"

re: fclean all
