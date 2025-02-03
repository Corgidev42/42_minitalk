/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:48:03 by dev               #+#    #+#             */
/*   Updated: 2025/01/08 09:52:12 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)haystack;
	i = 0;
	j = 0;
	if (*needle == 0)
		return (ptr);
	while (*haystack && i < len)
	{
		j = 0;
		if (ptr[i] == needle[j])
		{
			while (ptr[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return (ptr + i);
			}
		}
		i++;
	}
	return (NULL);
}
