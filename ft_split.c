/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:32:34 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/15 11:02:34 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

char	*ft_mal_word(char const *s, size_t start, size_t end)
{
	size_t	i;
	char	*word;

	word = malloc(sizeof (char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	size_t	nb;
	char	**tab;

	tab = malloc (sizeof (char *) * (ft_count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	nb = 0;
	i = 0;
	j = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == ft_strlen(s)) && j >= 0)
		{
			tab[nb++] = ft_mal_word(s, j, i);
			j = -1;
		}
		i++;
	}
	tab[nb] = '\0';
	return (tab);
}
