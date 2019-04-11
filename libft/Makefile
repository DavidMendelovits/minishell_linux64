# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/22 18:55:29 by dmendelo          #+#    #+#              #
#    Updated: 2018/11/18 13:12:57 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_memset.c ft_putchar.c ft_putnbr_base.c \
		ft_putstr.c ft_strlen.c ft_memalloc.c ft_strdup.c ft_strdup_range.c \
		ft_strrev.c ft_swap.c ft_atoi_base.c ft_strcmp.c ft_is_digit.c \
		ft_strcpy.c ft_strnew.c ft_strjoin.c ft_itoa_base.c ft_utoa_base.c \
		ft_strsplit.c ft_print_strings.c ft_strstr_index.c ft_strchr_index.c \
		trip_join.c ft_memcpy.c ft_memdel.c ft_strncmp.c

OBJ = ft_atoi.o ft_bzero.o ft_memset.o ft_putchar.o ft_putnbr_base.o \
		ft_putstr.o ft_strlen.o ft_memalloc.o ft_strdup.o ft_strdup_range.o \
		ft_strrev.o ft_swap.o ft_atoi_base.o ft_strcmp.o ft_is_digit.o \
		ft_strcpy.o ft_strnew.o ft_strjoin.o ft_itoa_base.o ft_utoa_base.o \
		ft_strsplit.o ft_print_strings.o ft_strstr_index.o ft_strchr_index.o \
		trip_join.o ft_memcpy.o ft_memdel.o ft_strncmp.o

B_PRINTF = b_printf/b_printf.c b_printf/specifiers1.c b_printf/specifiers2.c

GNL = gnl/get_next_line.c

B_PRINTF_OBJ = b_printf.o specifiers1.o specifiers2.o

GNL_OBJ = get_next_line.o

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) -c $(SRC) $(B_PRINTF) $(GNL) -I $(NAME)
	@ar rcs $(NAME) $(OBJ) $(B_PRINTF_OBJ) $(GNL_OBJ)

clean:
	@rm -rf $(OBJ) $(B_PRINTF_OBJ) $(GNL_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
