/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:50 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 15:10:26 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	received_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	received_ack = 1;
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		received_ack = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!received_ack)
			pause();
		i--;
	}
}

void	send_string(pid_t server_pid, const char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	char				*message;
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] 'message'\n");
		return (1);
	}
	if (!ft_isdigit(argv[1][0]))
	{
		ft_printf("Invalid PID. Please enter a valid number.\n");
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	send_string(server_pid, message);
	free(message);
	return (0);
}
