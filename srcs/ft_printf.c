/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:31:27 by saray             #+#    #+#             */
/*   Updated: 2021/02/08 10:53:37 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		retnb;
	int		nbchr;
	va_list	param;

	va_start(param, str);
	nbchr = 0;
	while (*str != '\0')
	{
		if (*str != '%')
		{
			ft_putchar(*str++);
			nbchr++;
			continue ;
		}
		str++;
		retnb = elem_print(&str, &param);
		if (retnb == -1)
			return (-1);
		nbchr = nbchr + retnb;
	}
	return (nbchr);
}
