/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:56:24 by saray             #+#    #+#             */
/*   Updated: 2021/02/02 09:56:30 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctostr(int c)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * 2);
	if (!ret)
		return (0);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
