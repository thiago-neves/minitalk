/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:35:13 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:35:14 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sinal;
	int	number;

	sinal = 1;
	i = 0;
	number = 0;
	while
		((str[i] != '\0') && (str[i] == ' ' || str[i] == '\f' ||
		str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sinal *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - 48);
	number = number * sinal;
	return (number);
}
