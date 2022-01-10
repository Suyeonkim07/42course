/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:58:11 by suykim            #+#    #+#             */
/*   Updated: 2020/07/02 13:50:58 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *set, char **line, int ret)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (set[i])
	{
		if (set[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(set))
	{
		*line = ft_substr(set, 0, i);
		tmp = ft_substr(set, i + 1, ft_strlen(set) - i);
		free(set);
		set = ft_strdup(tmp);
		free(tmp);
	}
	else if (ret == 0)
	{
		*line = set;
		set = NULL;
	}
	return (set);
}

char	*ft_save(char *buff, char *set)
{
	char		*tmp;

	if (set)
	{
		tmp = ft_strjoin(set, buff);
		free(set);
		set = ft_strdup(tmp);
		free(tmp);
	}
	else
		set = ft_strdup(buff);
	return (set);
}

int		get_next_line(int fd, char **line)
{
	static char *set;
	int			ret;
	char		buff[BUFFER_SIZE + 1];

	ret = 0;
	if (BUFFER_SIZE < 1 || line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		set = ft_save(buff, set);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret <= 0 && !set)
	{
		*line = ft_strdup("");
		return (ret);
	}
	set = ft_get_line(set, line, ret);
	if (ret <= 0 && !set)
		return (ret);
	return (1);
}
