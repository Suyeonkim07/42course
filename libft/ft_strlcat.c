/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:28:20 by suykim            #+#    #+#             */
/*   Updated: 2020/03/14 21:34:29 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;
	size_t m;

	len = 0;
	i = 0;
	j = 0;
	i = ft_strlen(dest);
	m = i;
	j = ft_strlen(src);
	if (i < size)
		len = i + j;
	else
		len = size + j;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[m + j] = src[j];
		j++;
		i++;
	}
	dest[m + j] = '\0';
	return (len);
}
