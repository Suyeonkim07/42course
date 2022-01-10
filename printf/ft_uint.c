/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:18:29 by suykim            #+#    #+#             */
/*   Updated: 2020/08/04 17:19:22 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_put_part_uint(char *u_int, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_treat_width(flags.dot - 1, ft_strlen(u_int) - 1, 1);
	count += ft_putstrdot(u_int, ft_strlen(u_int));
	return (count);
}
static	int	ft_put_uint(char *u_int, t_flags flags)
{
	int count;

	count = 0;
	if (flags.m == 1)
		count += ft_put_part_uint(u_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_int))
		flags.dot = ft_strlen(u_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_treat_width(flags.width, 0, 0);
	}
	else
		count += ft_treat_width(flags.width, ft_strlen(u_int), flags.zero);
	if (flags.m == 0)
		count += ft_put_part_uint(u_int, flags);
	return (count);
}

int			ft_treat_u(unsigned int uint, t_flags flags)
{
	char *u_int;
	int count;

	count = 0;
	uint = (unsigned int)(4294967295 + 1
				+ uint);
	if (flags.dot == 0 && uint == 0)
	{
		count += ft_treat_width(flags.width, 0, 0);
		return (count);
	}
	u_int = ft_uitoa(uint);
	count += ft_put_uint(u_int, flags);
	free(u_int);
	return (count);
}
