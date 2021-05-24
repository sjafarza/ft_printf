/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 23:42:24 by saray             #+#    #+#             */
/*   Updated: 2020/12/06 10:31:04 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_find(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	sta;
	size_t	ed;

	sta = 0;
	while (s1[sta] && ft_is_find(s1[sta], set))
		sta++;
	ed = ft_strlen(s1);
	while (ed > sta && ft_is_find(s1[ed - 1], set))
		ed--;
	str = (char *)malloc(sizeof(*s1) * (ed - sta + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (sta < ed)
		str[i++] = s1[sta++];
	str[i] = 0;
	return (str);
}
