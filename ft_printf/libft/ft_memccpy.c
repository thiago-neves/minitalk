/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:38:46 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:38:47 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*newdest;
	unsigned char	*newsrc;

	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		newdest[i] = newsrc[i];
		if (newsrc[i] == (unsigned char) c)
			return ((void *)(dest + i + 1));
		i++;
		n--;
	}
	return (0);
}
