/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:30:08 by dev               #+#    #+#             */
/*   Updated: 2025/01/31 16:11:53 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;

	i = 0;
	while (*s1 && is_set(*s1, set))
		s1++;
	while (s1[i])
		i++;
	while (*s1 && is_set(s1[i - 1], set))
		i--;
	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	return (str);
}
