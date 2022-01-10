/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:28:17 by suykim            #+#    #+#             */
/*   Updated: 2020/08/06 21:04:03 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_zero_flags(void)
{
	t_flags	flags;

	flags.m = 0;
	flags.star = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.type = 0;
	return (flags);
}

t_flags	ft_minus(t_flags flags)
{
	flags.m = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags	ft_star(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.zero = 0;
		flags.m = 1;
		flags.width *= -1;
	}
	return (flags);
}

int		ft_flag_p(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i] != '\0')
	{
		if (!ft_is_digit(str[i]) && !ft_is_type(str[i])
			&& !ft_is_flaglist(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->m == 0)
			flags->zero = 1;
		if (str[i] == '-')
			*flags = ft_minus(*flags);
		if (str[i] == '.')
			i = ft_dot(str, i, flags, args);
		if (str[i] == '*')
		{		
			*flags = ft_star(args, *flags);
		}
		if (ft_is_digit(str[i]))
			*flags = ft_digit(str[i], *flags);
		if (ft_is_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}
