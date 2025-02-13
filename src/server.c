/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:44:31 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 11:31:12 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_buffer(char **buffer)
{
	if (!*buffer)
	{
		*buffer = (char *)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
		if (!*buffer)
			exit(EXIT_FAILURE);
	}
}

void	store_character(char *buffer, int *buffer_index, char current_char)
{
	buffer[(*buffer_index)++] = current_char;
	if (current_char == '\0' || *buffer_index == INITIAL_BUFFER_SIZE - 1)
	{
		write(1, buffer, *buffer_index);
		write(1, "\n", 1);
		*buffer_index = 0;
	}
}

void	handle_bit_in_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit_index = 0, buffer_index = 0;
	static char	current_char = 0, *buffer = NULL;

	(void)context;
	init_buffer(&buffer);
	current_char = (current_char << 1) | (sig == SIGUSR2);
	if (++bit_index == 8)
	{
		store_character(buffer, &buffer_index, current_char);
		if (current_char == '\0')
			kill(info->si_pid, SIGUSR2);
		bit_index = 0;
		current_char = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

void	set_up_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_bit_in_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	set_up_signals();
	ft_printf("Server running. PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
