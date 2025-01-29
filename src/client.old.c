/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:49:47 by dev               #+#    #+#             */
/*   Updated: 2025/01/06 16:43:07 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	check_entry(char *number)
{
	int	i;
	int	is_digit;

	i = 0;
	is_digit = 1;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 0)
		{
			is_digit = 0;
			break ;
		}
		i++;
	}
	return (is_digit);
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
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
	pid_t		server_pid;
	char	*message;

	server_pid = 0;
	message = NULL;
	if (argc == 3)
	{
		if (check_entry(argv[1]) == 0)
		{
			ft_printf("error entry, enter only digit between 0 and 9");
			return (0);
		}
		server_pid = (pid_t)ft_atoi(argv[1]);
		message = ft_strdup(argv[2]);
		send_string(server_pid, message);
	}
	else
		ft_printf("./client [PID] 'message'");
	if (message)
		free(message);
	return (0);
}
