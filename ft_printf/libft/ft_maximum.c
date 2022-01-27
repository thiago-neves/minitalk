/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maximum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:38:38 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:38:39 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	maximum(int arg_size, ...)
{
	int		max;
	int		current;
	va_list	numbers;

	va_start(numbers, arg_size);
	max = va_arg(numbers, int);
	while (--arg_size > 0)
	{
		current = va_arg(numbers, int);
		if (current > max)
			max = current;
	}
	va_end(numbers);
	return (max);
}
