/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:32:15 by suykim            #+#    #+#             */
/*   Updated: 2020/08/06 20:12:36 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}

int		get_count(int s)
{
	int i;

	i = 1;
	while (s / 10 != 0)
	{
		i++;
		s = s / 10;
	}
	return (i);
}

char	*ft_itoa(long long n)
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
