/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:41:34 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:41:36 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	char		*ptrd1;
	char		*ptrd2;
	const char	*ptrs;

	if (!dest)
		return (0);
	ptrd1 = dest;
	ptrd2 = dest + destsize;
	ptrs = src;
	while (*ptrs && ptrd1 < ptrd2)
		*ptrd1++ = *ptrs++;
	if (ptrd1 < ptrd2)
		*ptrd1 = 0;
	else if (destsize > 0)
		ptrd1[-1] = 0;
	return (ft_strlen(src));
}
