/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:41 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 15:11:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ack_handler(int sig);
void	send_char(pid_t server_pid, char c);
void	send_string(pid_t server_pid, const char *str);
int		main(int argc, char *argv[]);
#endif
