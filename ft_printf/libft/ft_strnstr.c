/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:42:04 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:42:05 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	char	*ptrb;
	int		i;

	ptrb = (char *)big;
	if (ft_strlen(small) == 0)
		return (ptrb);
	while (len > 0 && *big)
	{
		i = 0;
		while (*big++ == small[i])
		{
			if (i++ == (int)ft_strlen(small) - 1)
				return (ptrb);
			if (--len <= 0)
				return (NULL);
		}
		len -= 1;
		if (i > 0)
		{
			len += i;
			big--;
		}
		ptrb = (char *)big;
	}
	return (NULL);
}
