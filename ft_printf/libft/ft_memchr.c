/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:38:52 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:38:53 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void			*rets;
	unsigned char	newc;
	unsigned char	*news;

	rets = (void *)s;
	newc = c;
	news = (unsigned char *)s;
	while (n > 0)
	{
		if (*news == newc)
			return (rets);
		news++;
		rets++;
		n--;
	}
	return (NULL);
}
