/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:12:18 by suykim            #+#    #+#             */
/*   Updated: 2020/04/21 00:14:22 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_count(int s)
{
	int				i;

	i = 1;
	while (s / 10 != 0)
	{
		i++;
		s = s / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s1;
	long long int	i;
	long long int	s;

	s = (long long int)n;
	i = get_count(n);
	if (n < 0)
	{
		s = s * -1;
		i = i + 1;
	}
	s1 = malloc(i + 1);
	if (!s1)
		return (NULL);
	s1[i--] = '\0';
	while (i != -1)
	{
		s1[i--] = s % 10 + '0';
		s = s / 10;
	}
	if (n < 0)
		s1[0] = '-';
	return (s1);
}
