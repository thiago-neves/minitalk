/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:39:15 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:39:17 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int					i;
	int					leng;
	unsigned char		*newdest;
	const unsigned char	*newsrc;

	leng = (int)len;
	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (newdest == 0 && newsrc == 0)
		return (dest);
	i = 0;
	if (newsrc < newdest)
		while (++i <= leng)
			newdest[leng - i] = newsrc[leng - i];
	else
		while (++i < leng)
			newdest[i] = newsrc[i];
	return (dest);
}
