/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:40:50 by ezeppa            #+#    #+#             */
/*   Updated: 2025/01/08 09:51:52 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n-- && *ptr && *ptr != (unsigned char)c)
		ptr++;
	if (*ptr != (unsigned char)c)
		return (NULL);
	return (ptr);
}
