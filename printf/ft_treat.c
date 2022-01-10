/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:59:54 by suykim            #+#    #+#             */
/*   Updated: 2020/08/06 17:35:03 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_treat_width(int width, int m, int zero)
{
	int count;

	count = 0;
	while (width - m > 0)
	{
		if(zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count++;
	}
	return (count);
}

int	ft_treat_c(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.m == 1)
		ft_putchar(c);
	count = ft_treat_width(flags.width, 1, 0);
	if (flags.m == 0)
		ft_putchar(c);
	return (count + 1);
}


int ft_treat_s(char *s, t_flags flags)
{
	int count;

	count = 0;
	if (!s)
		s = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(s))
		flags.dot = ft_strlen(s);
	if (flags.m == 1)
		count += ft_put_str(s, flags);
	if (flags.dot >= 0)
		count += ft_treat_width(flags.width, flags.dot, 0);
	else
		count += ft_treat_width(flags.width, ft_strlen(s), 0);
	if (flags.m == 0)
		count += ft_put_str(s, flags);
	return (count);
}

int	ft_treat(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_treat_c(va_arg(args, int), flags);
	else if (c == 's')
	{
		count = ft_treat_s(va_arg(args, char *), flags);
	}
	else if (c == 'p')
		count = ft_treat_p(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count = ft_treat_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_treat_u(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_treat_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_treat_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_treat_per(flags);
	return (count);
}

