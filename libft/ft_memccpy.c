/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 01:19:13 by suykim            #+#    #+#             */
/*   Updated: 2020/04/21 00:11:35 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	i = 0;
	d = dest;
	s = src;
	while (n != 0)
	{
		d[i] = s[i];
		if (s[i] == (char)c)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
