/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:40:59 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:41:00 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ptr = str;
	while (*s)
		*ptr++ = *s++;
	*ptr = 0;
	return (str);
}
