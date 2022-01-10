/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:08:42 by suykim            #+#    #+#             */
/*   Updated: 2020/08/04 17:10:36 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_per(t_flags flags)
{
	int count;

	count = 0;
	if (flags.m == 1)
		count += ft_putstrdot("%", 1);
	count += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.m == 0)
		count += ft_putstrdot("%", 1);
	return (count);
}
