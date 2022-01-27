/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:10:32 by coder             #+#    #+#             */
/*   Updated: 2022/01/23 21:49:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	add_info_to_struct(int signal, int client_process_id, t_data *new_data)
{
	static t_data	*data;

	if (new_data != NULL)
		data = new_data;
	data->current_signal = signal;
	if (data->client_process_id != client_process_id)
		data->current_bit = 0;
	data->client_process_id = client_process_id;
}

void	add_bit_to_byte(t_data *data)
{
	data->current_bit++;
	data->character <<= 1;
	if (data->current_signal == SIGUSR1)
		data->character += 1;
	if (kill(data->client_process_id, SIGUSR1) == -1)
		ft_exit("\nClient lost!\n");
}

void	signal_handler(int signal, siginfo_t *signal_info, void *context)
{
	(void)context;
	add_info_to_struct(signal, signal_info->si_pid, NULL);
}

void	init_server(t_data *data)
{
	data->signal_action.sa_flags = SA_SIGINFO;
	data->current_bit = 0;
	data->signal_action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &data->signal_action, NULL);
	sigaction(SIGUSR2, &data->signal_action, NULL);
	add_info_to_struct(0, 0, data);
	ft_printf("Server process id is %d\n", getpid());
}

int	main(void)
{
	t_data	data;

	init_server(&data);
	while (TRUE)
	{
		if (data.current_signal != SIGUSR1 || data.current_signal != SIGUSR2)
			pause();
		add_bit_to_byte(&data);
		data.current_signal = 0;
		if (data.current_bit == 8)
		{
			write(1, &data.character, 1);
			data.current_bit = 0;
		}
	}
}
