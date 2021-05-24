/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:09:14 by saray             #+#    #+#             */
/*   Updated: 2020/12/17 10:28:12 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (size != 0)
	{
		while (dst[i] && i < size)
			i++;
		j = 0;
		while (src[j] && j + i < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		if (j + i < size)
			dst[i + j] = '\0';
	}
	k = 0;
	while (src[k] != '\0')
		k++;
	return (k + i);
}
