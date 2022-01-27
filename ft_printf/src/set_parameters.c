/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:35:02 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:35:03 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	set_flags(const char *str, t_params *var_params)
{
	size_t	i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '0')
			var_params->has_zero = 1;
		if (str[i] == '-')
			var_params->has_minus = 1;
		i++;
	}
	return (i);
}

size_t	set_width(const char *str, t_params *var_params, va_list args)
{
	size_t	i;
	int		width_value;

	i = 0;
	if (*str == '*')
	{
		width_value = va_arg(args, int);
		if (width_value < 0)
		{
			var_params->has_minus = 1;
			width_value *= -1;
		}
		var_params->width_value = width_value;
		return (1);
	}
	else
	{
		var_params->width_value = ft_atoi(str);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

void	set_precision(char *str, t_params *var_params, va_list args)
{
	int		precision_value;
	char	*temp;

	if (*str == '.')
	{
		var_params->has_precision = 1;
		if (str[1] == '*')
		{
			precision_value = va_arg(args, int);
			temp = ft_itoa(precision_value);
			var_params->precision_value = ft_atoi(temp);
			free(temp);
		}
		else
			var_params->precision_value = ft_atoi(str + 1);
	}
}
