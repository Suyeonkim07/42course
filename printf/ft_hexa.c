/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:15:55 by suykim            #+#    #+#             */
/*   Updated: 2020/08/04 16:27:24 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_put_part_hexa(char *h, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_treat_width(flags.dot - 1, ft_strlen(h) - 1, 1);
	count += ft_putstrdot(h, ft_strlen(h));
	return (count);
}

static	int	ft_put_hexa(char *h, t_flags flags)
{
	int count;

	count = 0;
	if (flags.m == 1)
		count += ft_put_part_hexa(h, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(h))
		flags.dot = ft_strlen(h);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_treat_width(flags.width, 0, 0);
	}
	else
		count += ft_treat_width(flags.width, ft_strlen(h), flags.zero);
	if (flags.m == 0)
		count += ft_put_part_hexa(h, flags);
	return (count);
}

int			ft_treat_hexa(unsigned int hexa, int low, t_flags flags)
{
	char	*h;
	int		count;

	count = 0;
	hexa = (unsigned int)(4294967295 + 1
				+ hexa);
	if (flags.dot == 0 && hexa == 0)
	{
		count += ft_treat_width(flags.width, 0, 0);
		return (count);
	}
	h = ft_u_base((unsigned long long)hexa, 16);
	if (low == 1)
		h = ft_str_tolower(h);
	count += ft_put_hexa(h, flags);
	free(h);
	return (count);
}
