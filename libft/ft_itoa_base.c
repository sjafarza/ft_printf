/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:57:00 by saray             #+#    #+#             */
/*   Updated: 2021/02/02 11:40:23 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_error(char *base, long baselen)
{
	size_t	i;
	size_t	k;

	if (baselen <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		k = 0;
		while (base[k])
		{
			if (base[i] == base[k] && i != k)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

char		*ft_itoa_base(unsigned long long nb, char *base)
{
	char				tmp[100];
	char				*ret;
	unsigned long long	baselen;
	size_t				i;

	baselen = ft_strlen(base);
	if (check_error(base, baselen) == 0)
		return (0);
	i = 0;
	while (nb >= baselen)
	{
		tmp[i++] = base[nb % baselen];
		nb /= baselen;
	}
	tmp[i++] = base[nb % baselen];
	tmp[i] = '\0';
	ret = ft_strdup(tmp);
	if (!ret)
		return (0);
	return (ft_revstr(ret));
}
