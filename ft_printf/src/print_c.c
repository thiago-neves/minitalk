/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:16 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:17 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_c(va_list args, t_params *var_params)
{
	char	str;
	char	*new_str;
	size_t	size;

	str = va_arg(args, int);
	new_str = ft_calloc(2, sizeof(char));
	new_str[0] = str;
	if (new_str[0] == 0)
	{
		var_params->width_value--;
		size = print_in_screen(new_str, var_params) + 1;
		free(new_str);
		return (size);
	}
	else
	{
		size = print_in_screen(new_str, var_params);
		free(new_str);
		return (size);
	}
}
