/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:49:49 by dev               #+#    #+#             */
/*   Updated: 2025/01/06 16:45:14 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_handler(int sig)
{
	static int	bit_index = 0;
	static char	current_char = 0;

	if (sig == SIGUSR1)
		current_char = current_char << 1;
	else if (sig == SIGUSR2)
		current_char = (current_char << 1) | 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		current_char = 0;
		bit_index = 0;
	}

}

int	main(void)
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
	ft_printf("Server running. PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
