/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:40:22 by marvin            #+#    #+#             */
/*   Updated: 2025/01/08 10:32:18 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(char *s, long n, int i)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	if (n > 9)
	{
		ft_recursive(s, n / 10, i - 1);
		s[i] = (n % 10) + '0';
	}
	else
		s[i] = n + '0';
}

char	*ft_litoa(long n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(sizeof(char) * 12);
		if (!ptr)
			return (ptr);
		ft_strlcpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	ptr = malloc(sizeof(char) * (ft_long_size(n) + 1));
	if (!ptr)
		return (NULL);
	ft_recursive(ptr, n, (ft_long_size(n) - 1));
	ptr[ft_long_size(n)] = '\0';
	return (ptr);
}
