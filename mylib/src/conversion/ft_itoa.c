/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:25:38 by dev               #+#    #+#             */
/*   Updated: 2025/01/08 09:42:12 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	number_size(int n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_cast(char *nb, int n, size_t len)
{
	if (n == 0)
	{
		nb[0] = '0';
		return (nb);
	}
	if (n < 0)
	{
		nb[0] = '-';
		n = -n;
	}
	while (n)
	{
		nb[--len] = n % 10 + '0';
		n /= 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	len;

	if (n == -2147483648)
	{
		nb = malloc(sizeof(char) * 12);
		if (nb == NULL)
			return (NULL);
		ft_strlcpy(nb, "-2147483648", 12);
		return (nb);
	}
	len = number_size(n);
	nb = malloc(sizeof(char) * (len + 1));
	if (nb == NULL)
		return (NULL);
	nb = ft_cast(nb, n, len);
	nb[len] = '\0';
	return (nb);
}
