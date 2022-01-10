/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:41:10 by suykim            #+#    #+#             */
/*   Updated: 2020/08/04 15:51:55 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_n_len(long n)
{
	size_t	n_len;
	int		i;

	n_len = 0;
	i = 0;
	if (n < 0)
	{
		n_len++;
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static	char	*ft_gen(char *s, long nbr, int len, int i)
{
	if (nbr != 0)
		s = malloc(sizeof(char) * (len + 1));
	else
		return (s = ft_strdup("0"));
	if (!s)
		return (0);
	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	s[len] = '\0';
	while (--len)
	{
		s[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (i == 1)
		s[0] = '-';
	else
		s[0] = (nbr % 10) + '0';
	return (s);
}

char			*ft_uitoa(unsigned int n)
{
	int		len;
	char	*s;
	long	nbr;
	int		i;

	nbr = n;
	len = ft_n_len(nbr);
	s = 0;
	i = 0;
	if (!(s = ft_gen(s, nbr, len, i)))
		return (0);
	return (s);
}
