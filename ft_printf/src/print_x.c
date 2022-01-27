/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:57 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:58 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_x_upper(va_list args, t_params *var_params)
{
	int		n;
	char	*str;
	size_t	size;

	n = va_arg(args, int);
	str = ft_int_to_hex(n);
	n = -1;
	while (str[++n])
		str[n] = ft_toupper(str[n]);
	if (*str == '0' && var_params->precision_value == 0 \
		&& var_params->has_precision)
		*str = '\0';
	size = print_in_screen(str, var_params);
	free(str);
	return (size);
}

size_t	print_x(va_list args, t_params *var_params)
{
	int		n;
	char	*str;
	size_t	size;

	n = va_arg(args, int);
	str = ft_int_to_hex(n);
	if (*str == '0' && var_params->precision_value == 0 \
		&& var_params->has_precision)
		*str = '\0';
	size = print_in_screen(str, var_params);
	free(str);
	return (size);
}
