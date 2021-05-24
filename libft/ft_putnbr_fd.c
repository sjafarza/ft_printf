/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 05:32:18 by saray             #+#    #+#             */
/*   Updated: 2020/12/18 06:17:53 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		nb1;
	int		nb2;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
	}
	if (n != -2147483648)
	{
		nb1 = n;
		nb2 = n;
		nb1 = nb1 % 10;
		nb2 = nb2 / 10;
		if (nb2 != 0)
			ft_putnbr_fd(nb2, fd);
		ft_putchar_fd(nb1 + '0', fd);
	}
}
