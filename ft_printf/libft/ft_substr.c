/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:42:24 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:42:25 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (!s)
		return (0);
	str = malloc(len + 1);
	if (!str || (int)len == -1)
		return (0);
	ptr = str;
	while (len-- > 0 && start < ft_strlen(s))
		*ptr++ = s[start++];
	*ptr = 0;
	return (str);
}
