/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:36:41 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/14 22:25:59 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*begin;
	char	*end;
	char	*trim;
	size_t	trim_len;

	len = ft_strlen(s1);
	begin = (char *)s1;
	end = (char *)s1 + len - 1;
	while (*begin && ft_strchr(set, *begin) != NULL)
		begin++;
	while (end > begin && ft_strchr(set, *end) != NULL)
		end--;
	trim_len = end - begin + 1;
	trim = malloc (sizeof (char) * (trim_len + 1));
	if (trim == NULL)
		return (NULL);
	len = 0;
	while (len < trim_len)
	{
		trim[len] = begin[len];
		len++;
	}
	trim[len] = '\0';
	return (trim);
}
