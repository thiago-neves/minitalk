/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:34:00 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:34:01 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

size_t			ft_printf(const char *str, ...);
size_t			parameters_length(const char *str, size_t *skip_len);

typedef struct s_params
{
	char		type;
	char		has_zero;
	char		has_minus;
	int			has_width;
	int			has_precision;
	int			width_value;
	int			precision_value;
}				t_params;

size_t			print_variable(const char *str, size_t *skip_len, va_list args);
void			get_params(const char *str, size_t skip_len, va_list args,
					t_params *var_params);
int				set_flags(const char *str, t_params *var_params);
size_t			set_width(const char *str, t_params *var_params, va_list args);
void			set_precision(char *str, t_params *var_params, va_list args);
size_t			print_c(va_list args, t_params *var_params);
size_t			print_d(va_list args, t_params *var_params);
size_t			print_p(va_list args, t_params *var_params);
size_t			print_pcnt(t_params *var_params);
size_t			print_s(va_list args, t_params *var_params);
size_t			print_u(va_list args, t_params *var_params);
size_t			print_x(va_list args, t_params *var_params);
size_t			print_x_upper(va_list args, t_params *var_params);
size_t			print_in_screen(char *str, t_params *var_params);
char			*ft_utoa(unsigned int n);
void			print_atributes(t_params *var_params);
int				maximum(int arg_size, ...);

#endif
