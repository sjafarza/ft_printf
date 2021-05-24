/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 08:49:48 by saray             #+#    #+#             */
/*   Updated: 2020/12/05 09:47:30 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest)
		return (NULL);
	i = 0;
	d = dest;
	s = str;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
