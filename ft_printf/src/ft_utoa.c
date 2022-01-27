/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:09 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:10 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	number(unsigned int nb)
{
	if (nb == 0)
		return (1);
	return (1 + number(nb / 10));
}

static char	*affect(char *s, unsigned int num, unsigned int i)
{
	unsigned int	l;

	l = 0;
	*s = num + 48;
	l = num;
	s[i + 1] = '\0';
	while (l != 0)
	{
		s[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (s);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	len;
	char			*dst;

	if (n > 0)
		len = number(n) - 1;
	else
		len = number(n);
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	return (affect(dst, n, len - 1));
}
