/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:10:37 by coder             #+#    #+#             */
/*   Updated: 2022/01/18 18:10:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	long	number;
	size_t	sign;
	size_t	i;

	number = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	return (sign * number);
}

int	signal_received(int signal)
{
	static int	current_signal;
	int			old_signal;

	old_signal = current_signal;
	current_signal = signal;
	return (old_signal);
}

int	is_number(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] < 48 || string[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	verify_client_arguments(int argc, char **argv)
{
	if (argc != 3)
		ft_exit("USAGE: ./client [SERVER PID] [MESSAGE]\n");
	if (is_number(argv[1]) == 0)
		ft_exit("WRONG PID\n");
}
