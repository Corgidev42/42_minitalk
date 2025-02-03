/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:53:07 by dev               #+#    #+#             */
/*   Updated: 2025/01/08 09:45:57 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	charac;
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	charac = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == charac)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
