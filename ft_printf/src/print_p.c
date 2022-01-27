/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:32 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:33 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_p(va_list args, t_params *var_params)
{
	long long	n;
	char		*str;
	size_t		end;
	char		*temp_str;
	int			len;

	n = va_arg(args, long long);
	str = ft_int_to_hex(n);
	if (var_params->has_precision && var_params->precision_value == 0 && n == 0)
		*str = 0;
	len = ft_strlen(str);
	if (var_params->precision_value > len && !var_params->has_minus)
	{
		temp_str = ft_calloc(var_params->precision_value - len, sizeof(char));
		ft_memset(temp_str, '0', var_params->precision_value - len);
		str = ft_strjoin(temp_str, str);
	}
	temp_str = ft_strjoin("0x", str);
	end = print_in_screen(temp_str, var_params);
	free(str);
	free(temp_str);
	return (end);
}
