/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:06:29 by suykim            #+#    #+#             */
/*   Updated: 2020/08/06 20:59:16 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_put_part_int(char *d, long long d_i, t_flags flags)
{
	int count;

	count = 0;
	printf("w:%d\n",flags.width);
	printf("d:%d",flags.dot);
	if (d_i < 0 && flags.dot >= 0)
	{
		ft_putchar('-');
	}
	if (flags.dot >= 0)
		count += ft_treat_width(flags.dot - 1, ft_strlen(d) - 1, 1);
	count += ft_putstrdot(d, ft_strlen(d));
	return (count);
}

static	int	ft_put_int(char *d, long long d_i, t_flags flags)
{
	int count;

	count = 0;
	if (flags.m == 1)
		count += ft_put_part_int(d, d_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d))
		flags.dot = ft_strlen(d);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_treat_width(flags.width, 0, 0);
	}
		else
	{
		count += ft_treat_width(flags.width, ft_strlen(d), flags.zero);
	}
		if (flags.m == 0)
	{
		count += ft_put_part_int(d, d_i, flags);
	}
	return (count);
}

int			ft_treat_int(long long i, t_flags flags)
{
	char	*d;
	long long		d_i;
	int		count;

	d_i = i;
	count = 0;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_treat_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{ 
		if (flags.zero == 1 && flags.dot == -1)
		{
			ft_putstrdot("-", 1);
		}
		i = i * -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	d= ft_itoa(i);
	count += ft_put_int(d, d_i, flags);
	free(d);
	return (count);
}
