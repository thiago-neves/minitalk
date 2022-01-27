/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:39:08 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:39:09 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*newdest;
	const unsigned char	*newsrc;

	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (newdest == 0 && newsrc == 0)
		return (dest);
	while (n > 0)
	{
		*newdest = *newsrc;
		newdest++;
		newsrc++;
		n--;
	}
	return (dest);
}
