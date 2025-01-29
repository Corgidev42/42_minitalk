/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:44:31 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/06 17:58:47 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INITIAL_BUFFER_SIZE 4096

void	manage_buffer_memory(char **buffer, int *buffer_size)
{
	if (*buffer_size == 0)
	{
		*buffer = (char *)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
		if (!*buffer)
		{
			ft_printf("malloc");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		*buffer = (char *)ft_realloc(*buffer, *buffer_size * 2 * sizeof(char));
		if (!*buffer)
		{
			ft_printf("realloc");
			exit(EXIT_FAILURE);
		}
	}
}

void	handle_bit_in_signal(int sig, char *current_char)
{
	if (sig == SIGUSR1)
		*current_char = *current_char << 1;
	else if (sig == SIGUSR2)
		*current_char = (*current_char << 1) | 1;
}

void	reset_char_and_buffer(char *current_char, int *bit_index)
{
	*current_char = 0;
	*bit_index = 0;
}

void	signal_handler(int sig)
{
	static int	bit_index = 0;
	static char	current_char = 0;
	static char	*buffer = NULL;
	static int	buffer_index = 0;
	static int	buffer_size = INITIAL_BUFFER_SIZE;

	if (!buffer)
		manage_buffer_memory(&buffer, &buffer_size);
	handle_bit_in_signal(sig, &current_char);
	bit_index++;
	if (bit_index == 8)
	{
		buffer[buffer_index++] = current_char;
		if (current_char == '\0' || buffer_index == buffer_size - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
		if (buffer_index == buffer_size - 1)
		{
			buffer_size *= 2;
			manage_buffer_memory(&buffer, &buffer_size);
		}
		reset_char_and_buffer(&current_char, &bit_index);
	}
}

void	set_up_signals(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = signal_handler;
	sa2.sa_handler = signal_handler;
	sigemptyset(&sa1.sa_mask);
	sigemptyset(&sa2.sa_mask);
	sa1.sa_flags = 0;
	sa2.sa_flags = 0;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
}

int	main(void)
{
	set_up_signals();
	ft_printf("Server running. PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
