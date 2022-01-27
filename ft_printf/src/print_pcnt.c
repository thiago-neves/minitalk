/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:38 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:39 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_pcnt(t_params *var_params)
{
	char	*str;
	size_t	size;

	str = ft_calloc(2, sizeof(char));
	*str = '%';
	size = print_in_screen(str, var_params);
	free(str);
	return (size);
}
