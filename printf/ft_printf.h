/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:10:07 by suykim            #+#    #+#             */
/*   Updated: 2020/08/06 20:12:57 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef	struct	s_flag
{
	int	m;
	int	zero;
	int	width;
	int	dot;
	int	type;
	int	star;
}				t_flags;
int				get_count(int s);
char			*ft_itoa(long long n);
t_flags			ft_zero_flags(void);
t_flags			ft_minus(t_flags flags);
t_flags			ft_digit(char c, t_flags flags);
int				ft_dot(const char *str, int i, t_flags *flags, va_list args);
t_flags			ft_star(va_list args, t_flags flags);
int				ft_is_type(int a);
int				ft_is_flaglist(int a);
int				ft_putstrdot(char *s, int dot);
int				ft_put_str(char *s, t_flags flags);
int				ft_flag_p(const char *str, int i, t_flags *flags, va_list args);
int				ft_process(const char *str, va_list args);
int				ft_printf(const char *fmt, ...);
size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
int				ft_putchar2(char c);
char			*ft_strdup(const char *s1);
int				ft_is_digit(int c);
int				ft_putstr(char *content);
int				ft_tolower(int c);
char			*ft_str_tolower(char *str);
char			*ft_u_base(unsigned long long u, int base);
int				ft_treat_width(int width, int m, int zero);
int				ft_treat_int(long long i, t_flags flags);
int				ft_treat_c(char c, t_flags flags);
int				ft_treat_s(char *c, t_flags flags);
int				ft_treat_u(unsigned int uint, t_flags flags);
char			*ft_uitoa(unsigned int n);
int				ft_treat_hexa(unsigned int hexa, int low, t_flags flags);
int				ft_treat_per(t_flags flags);
int				ft_treat(int c, t_flags flags, va_list args);
int				ft_treat_p(unsigned long long u, t_flags flags);

#endif
