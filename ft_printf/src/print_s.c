/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:43 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:44 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	compute_size(char *str, char *temp_str, t_params *var_params)
{
	size_t	size;

	size = print_in_screen(str, var_params);
	if (temp_str != NULL)
		free(temp_str);
	return (size);
}

size_t	print_s(va_list args, t_params *var_params)
{
	char	*str;
	char	*temp_str;
	int		i;

	i = 0;
	temp_str = NULL;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		temp_str = ft_calloc(7, sizeof(char));
		ft_strlcpy(temp_str, "(null)", 7);
		str = temp_str;
		i = 1;
	}
	if (var_params->has_precision && var_params->precision_value >= 0 \
		&& var_params->precision_value < (int)ft_strlen(str))
	{
		temp_str = ft_calloc(var_params->precision_value + 1, sizeof(char));
		ft_strlcpy(temp_str, str, var_params->precision_value + 1);
		if (i == 1)
			free(str);
		str = temp_str;
	}
	return (compute_size(str, temp_str, var_params));
}
