/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:39:52 by saray             #+#    #+#             */
/*   Updated: 2020/12/17 07:20:23 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	ft_rev(char *s)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(s);
	i = 0;
	while (i < (len / 2))
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
}

static int	ft_is_neg(int n)
{
	int	neg;

	if (n < 0)
		neg = -1;
	else
		neg = +1;
	return (neg);
}

static int	get_nb_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		neg;
	size_t	len;

	neg = ft_is_neg(n);
	if (!(s = ft_calloc(get_nb_size(n) + neg + 1, sizeof(*s))))
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		len = 1;
	}
	else
		len = 0;
	while (n != 0)
	{
		s[len++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (neg == -1)
		s[len++] = '-';
	s[len] = '\0';
	ft_rev(s);
	return (s);
}
