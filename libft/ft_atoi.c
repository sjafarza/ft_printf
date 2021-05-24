/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:51:22 by saray             #+#    #+#             */
/*   Updated: 2020/12/16 07:59:49 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	t;

	if (!nptr)
		return (0);
	i = 0;
	neg = 1;
	t = 0;
	while ((nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' \
			|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		t = (t * 10) + (nptr[i] - '0');
		i++;
	}
	return (t * neg);
}
