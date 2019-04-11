/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:39:55 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/18 13:12:45 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(const int fd, char **line);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr_base(unsigned long long number, int base);
void			*ft_memset(void *s, int c, size_t n);
void			ft_memdel(void **ptr);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
int				ft_strlen(const char *str);
int				b_printf(const char *format, ...);
char			*ft_strdup(const char *str);
char			*ft_strdup_range(const char *str, int begin, int end);
char			*ft_strrev(char *str);
void			ft_swap(int *a, int *b);
int				ft_atoi_base(char *int_, char *base);
int				ft_strcmp(char *s1, char *s2);
int 			ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_is_digit(char c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strnew(size_t size);
char			*ft_strjoin(const char *s1, const char *s2);
char			*trip_join(const char *s1, const char c, const char *s2);
char			*ft_itoa_base(__intmax_t nbr, char *base, unsigned int radix);
char			*ft_utoa_base(__uintmax_t nbr, char *base, unsigned int radix);
char			**ft_strsplit(char *str);
void			ft_print_strings(char **strings);
int				ft_strstr_index(const char *haystack, const char *needle);
unsigned		ft_numlen_base(__intmax_t nbr, unsigned int radix);
int				ft_strchr_index(const char *s, int c);

#endif
