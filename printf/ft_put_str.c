/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:35:47 by suykim            #+#    #+#             */
/*   Updated: 2020/08/04 15:40:43 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrdot(char *s, int len)
{
	int count;

	count = 0;
	while (s[count] && count < len)
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count);
}

int	ft_put_str(char *s, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_treat_width(flags.dot, ft_strlen(s), 0);
		count += ft_putstrdot(s, flags.dot);
	}
	else
		count += ft_putstrdot(s, ft_strlen(s));
	return (count);
}
