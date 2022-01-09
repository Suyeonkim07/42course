/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:11:55 by suykim            #+#    #+#             */
/*   Updated: 2020/06/24 16:54:33 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	j;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	j = 0;
	if (!(d = (char *)malloc(len + 1)))
		return (NULL);
	while (len > 0 && s_len > start)
	{
		d[j] = s[start + j];
		j++;
		len--;
	}
	d[j] = '\0';
	return (d);
}
