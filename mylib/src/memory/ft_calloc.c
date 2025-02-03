/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:59:02 by dev               #+#    #+#             */
/*   Updated: 2025/01/08 09:45:31 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*tab;

	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}
