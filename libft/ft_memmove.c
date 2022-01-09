/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:32:26 by suykim            #+#    #+#             */
/*   Updated: 2020/04/21 18:43:23 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = -1;
	d = (char *)dest;
	s = (const char *)src;
	if (len == 0 || dest == src)
		return (dest);
	if (s < d)
	{
		while (len != 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
	{
		while (++i < len)
		{
			d[i] = s[i];
		}
	}
	return (dest);
}
