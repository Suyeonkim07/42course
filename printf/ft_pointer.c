/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:15:00 by suykim            #+#    #+#             */
/*   Updated: 2020/08/06 18:08:17 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(unsigned long long ull_s, int base, char *p, int count)
{
	while (ull_s != 0)
	{
		if ((ull_s % base) < 10)
			p[count - 1] = (ull_s % base) + 48;
		else
			p[count - 1] = (ull_s % base) + 55;
		ull_s /= base;
		count--;
	}
	return (p);
}

char		*ft_u_base(unsigned long long u, int base)
{
	char				*p;
	unsigned long long	ull;
	int					count;

	p = 0;
	count = 0;
	ull = u;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(p = malloc(sizeof(char) * (count + 1))))
		return (0);
	p[count] = '\0';
	p = treat_base(u, base, p, count);
	return (p);
}

char		*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static	int	ft_put_p(char *p, t_flags flags)
{
	int count;

	count = 0;
	count += ft_putstrdot("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_treat_width(flags.dot, ft_strlen(p), 1);
		count += ft_putstrdot(p, flags.dot);
	}
	else
		count += ft_putstrdot(p, ft_strlen(p));
	return (count);
}

int			ft_treat_p(unsigned long long u, t_flags flags)
{
	char	*p;
	int		count;

	count = 0;
	if (u == 0 && flags.dot == 0)
	{
		count += ft_treat_width(flags.width, 2, 0);
		count += ft_putstrdot("0x", 2);
		// count += ft_treat_width(flags.width, 0, 0);
		return (count);
	}
	p = ft_u_base(u, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
	{
		flags.dot = ft_strlen(p);
	}
	if (flags.m == 1)
		count += ft_put_p(p, flags);
	count += ft_treat_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.m == 0)
		count += ft_put_p(p, flags);
	free(p);
	return (count);
}
