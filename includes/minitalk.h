/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:15:51 by coder             #+#    #+#             */
/*   Updated: 2022/01/18 18:18:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../ft_printf/ft_printf.h"

# define TRUE 1

typedef struct s_data
{
	unsigned int		character;
	int					current_bit;
	struct sigaction	signal_action;
	int					current_signal;
	int					client_process_id;
}				t_data;

int				ft_exit(char *string);
int				ft_atoi(const char *str);
int				signal_received(int signal);
void			verify_client_arguments(int argc, char **argv);
#endif
