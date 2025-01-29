/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:29 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 15:13:17 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	init_buffer(char **buffer);
void	store_character(char *buffer, int *buffer_index, char current_char);
void	handle_bit_in_signal(int sig, siginfo_t *info, void *context);
void	set_up_signals(void);
int		main(void);

#endif
