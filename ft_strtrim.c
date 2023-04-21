/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:36:41 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/21 14:57:32 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		j;
	int		res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		res = 0;
	else
		res = (j - i) + 1;
	dest = malloc(sizeof(char) * (res + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (s1 + i), res + 1);
	return (dest);
}
