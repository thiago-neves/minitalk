/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:42:15 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:42:16 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(int c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_in(s1[i], set))
		i++;
	while (is_in(s1[j], set) && j > 0)
		j--;
	if (j < i)
	{
		str = malloc(1);
		*str = 0;
		return (str);
	}
	str = malloc(j - i + 2);
	if (!str)
		return (0);
	s1 += i;
	ft_strlcpy(str, s1, j - i + 2);
	return (str);
}
