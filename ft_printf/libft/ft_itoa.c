/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:36:43 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:36:44 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pot(int n, int p)
{
	int	nbr;

	if (p < 0)
		return (0);
	nbr = 1;
	while (p-- > 0)
	{
		nbr *= n;
	}
	return (nbr);
}

int	number_of_digits(int n)
{
	int	ndigit;

	ndigit = 0;
	while (n != 0)
	{
		n /= 10;
		ndigit++;
	}
	return (ndigit);
}

int	modulo(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*ptr;
	int		digit;

	digit = number_of_digits(n);
	str = malloc(digit + 2);
	if (!str)
		return (0);
	ptr = str;
	if (n < 0)
	{
		*ptr = '-';
		ptr++;
	}
	if (digit == 0)
		*ptr++ = 48;
	while (digit-- > 0)
	{
		*ptr++ = modulo(n / pot(10, digit)) + 48;
		n -= (n / pot(10, digit)) * pot(10, digit);
	}
	*ptr = 0;
	return (str);
}
