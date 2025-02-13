/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:29 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 11:31:05 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <libft.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define INITIAL_BUFFER_SIZE 4096

/**
 * @brief Initialise le buffer si ce n'est pas déjà fait.
 *
 * @param buffer Pointeur vers le buffer à initialiser.
 */
void	init_buffer(char **buffer);

/**
 * @brief Stocke un caractère dans le buffer et l'affiche si nécessaire.
 *

	* Ajoute le caractère au buffer. Si le caractère est '\0' ou si le buffer est plein,
 * le contenu est affiché et le buffer est réinitialisé.
 *
 * @param buffer Le buffer où stocker les caractères.
 * @param buffer_index L'index courant dans le buffer.
 * @param current_char Le caractère à ajouter.
 */
void	store_character(char *buffer, int *buffer_index, char current_char);

/**
 * @brief Gère la réception d'un bit par signal.
 *

	* Construit un caractère bit par bit en fonction des signaux SIGUSR1 et SIGUSR2 reçus.
 * Lorsqu'un caractère est complété,
	il est stocké dans le buffer et affiché si nécessaire.

	* Envoie un accusé de réception au client après chaque bit et un signal final après '\0'.
 *
 * @param sig Le signal reçu.
 * @param info Informations sur le signal et l'expéditeur.
 * @param context Non utilisé.
 */
void	handle_bit_in_signal(int sig, siginfo_t *info, void *context);

/**
 * @brief Configure les gestionnaires de signaux pour SIGUSR1 et SIGUSR2.
 *

	* Utilise sigaction pour attacher handle_bit_in_signal aux signaux SIGUSR1 et SIGUSR2.
 */
void	set_up_signals(void);

#endif
