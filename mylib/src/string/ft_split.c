/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:55:16 by dev               #+#    #+#             */
/*   Updated: 2025/01/08 09:50:38 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !(s[i] == c))
				i++;
		}
	}
	return (count);
}

int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && !(s[len] == c))
		len++;
	return (len);
}

void	free_all(char **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
	return ;
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		word_count;

	word_count = ft_word_count(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = ft_substr(s, 0, ft_word_len(s, c));
		if (!result[i])
		{
			free_all(result, i);
			return (NULL);
		}
		s += ft_word_len(s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
