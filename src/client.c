/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:10:28 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 13:23:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(unsigned int process_id, int signal)
{
	int	max_sleep;
	int	sleep;

	sleep = 0;
	max_sleep = 500;
	while (signal_received(0) == 0)
	{
		if (sleep > max_sleep)
			ft_exit("ERROR: Timeout!\n");
		if (kill(process_id, signal) == -1)
			ft_exit("ERROR: Server lost\n");
		usleep(2500);
		sleep++;
	}
}

void	send_char(unsigned int server_process_id, unsigned char byte)
{
	unsigned int	bit;

	bit = 1 << 7;
	while (bit)
	{
		if (byte & bit)
			send_signal(server_process_id, SIGUSR1);
		else
			send_signal(server_process_id, SIGUSR2);
		usleep(500);
		bit >>= 1;
	}
}

void	send_string(unsigned int server_process_id, const char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		send_char(server_process_id, string[i]);
		i++;
	}
	send_char(server_process_id, '\n');
}

void	signal_handler(int signal)
{
	signal_received(signal);
}

int	main(int argc, char **argv)
{
	char				*string;
	unsigned int		server_process_id;

	verify_client_arguments(argc, argv);
	string = argv[2];
	signal(SIGUSR1, signal_handler);
	server_process_id = ft_atoi(argv[1]);
	send_string(server_process_id, string);
	ft_printf("Successfully sent message to %d!\n", server_process_id);
	return (0);
}
