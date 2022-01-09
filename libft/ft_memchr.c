/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:16:17 by suykim            #+#    #+#             */
/*   Updated: 2020/03/01 15:42:18 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *a;

	a = (char *)s;
	while (n > 0)
	{
		if (*a == (char)c)
			return (a);
		n--;
		a++;
	}
	return (0);
}
