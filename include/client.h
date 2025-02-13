/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:41 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 11:30:01 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

extern volatile sig_atomic_t g_received_ack;

/**
 * @brief Gère le signal d'accusé de réception provenant du serveur.
 *
 * @param sig Le numéro du signal reçu.
 */
void	ack_handler(int sig);

/**
 * @brief Envoie un caractère au serveur en utilisant des signaux.
 *
 * Envoie les bits du caractère un par un au serveur via SIGUSR1 et SIGUSR2.
 * Attend un accusé de réception après chaque bit.
 *
 * @param server_pid Le PID du processus serveur.
 * @param c Le caractère à envoyer.
 */
void	send_char(pid_t server_pid, char c);

/**
 * @brief Envoie une chaîne de caractères au serveur.
 *
 * Envoie chaque caractère de la chaîne, y compris le terminateur nul,
	au serveur.
 * Attend un accusé de réception après le dernier caractère nul.
 *
 * @param server_pid Le PID du processus serveur.
 * @param str La chaîne de caractères à envoyer.
 */
void	send_string(pid_t server_pid, const char *str);

#endif
