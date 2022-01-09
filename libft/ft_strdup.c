/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:11:25 by suykim            #+#    #+#             */
/*   Updated: 2020/04/21 17:41:31 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	len = len - 1;
	while (len >= 0)
	{
		ptr[i] = s1[i];
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
