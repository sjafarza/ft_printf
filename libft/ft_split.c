/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 05:48:28 by saray             #+#    #+#             */
/*   Updated: 2020/12/16 08:02:26 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_alloc_spl(char const *s, char c)
{
	size_t	i;
	size_t	cw;
	char	**spl;

	cw = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			++i;
		s = s + i;
		if (i != 0)
			cw++;
	}
	spl = (char **)malloc(sizeof(s) * (cw + 1));
	if (!spl)
		return (NULL);
	return (spl);
}

static void			*ft_free_all(char **split, size_t t)
{
	size_t	i;

	i = 0;
	while (i < t)
	{
		free((void *)split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int			ft_len_word(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char			**ft_do(char const *s, char **split, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		split[j] = (char *)malloc(sizeof(char) * ft_len_word(s, c, i) + 1);
		if (split[j] == NULL)
			return (ft_free_all(split, (size_t)j));
		while (s[i] != '\0' && s[i] != c)
			split[j][k++] = s[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}

char				**ft_split(char const *s, char c)
{
	char		**split;
	const char	*cs;
	int			l;
	int			i;

	cs = s;
	if (!(split = ft_alloc_spl(s, c)))
		return (NULL);
	l = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i)
			l++;
		s = s + i;
	}
	split = ft_do(cs, split, c, l);
	return (split);
}
