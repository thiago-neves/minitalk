/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:42:10 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:42:11 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)str;
	i = ft_strlen(str);
	if (i == 0 && c == 0)
		return (ptr);
	if (i == 0 && c != 0)
		return (0);
	ptr += i;
	while (i >= 0)
	{
		if (str[i] == c)
			return (ptr);
		ptr--;
		i--;
	}
	return (0);
}
