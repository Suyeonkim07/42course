/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 00:28:10 by suykim            #+#    #+#             */
/*   Updated: 2020/04/21 15:14:21 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	while (s1[s] && ft_strchr(set, s1[s]))
		s++;
	e = ft_strlen(s1 + s);
	if (e)
		while (s1[e + s - 1] != 0 && ft_strchr(set, s1[e + s - 1]) != 0)
			e--;
	if (!(new = malloc(sizeof(char) * e + 1)))
		return (NULL);
	ft_strncpy(new, s1 + s, e);
	new[e] = '\0';
	return (new);
}
