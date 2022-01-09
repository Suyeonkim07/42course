/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:06:45 by suykim            #+#    #+#             */
/*   Updated: 2020/04/21 00:15:14 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int s;

	s = (long long int)n;
	if (s == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (s < 0)
	{
		write(fd, "-", 1);
		s = -1 * s;
	}
	if (s > 9)
		ft_putnbr_fd(s / 10, fd);
	ft_putchar_fd((s % 10) + 48, fd);
}
