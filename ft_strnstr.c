/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:02:02 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/14 15:49:34 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*nbig;
	char	*nlittle;

	i = 0;
	nbig = (char *)big;
	nlittle = (char *)little;
	count = ft_strlen(nlittle);
	if (count == 0 || nbig == nlittle)
		return (nbig);
	while (nbig[i] != '\0' && i < len)
	{
		j = 0;
		while (nbig[i + j] != '\0' && nlittle[j] != '\0'
			&& nbig[i + j] == nlittle[j] && i + j < len)
			j++;
		if (j == count)
			return (nbig + i);
		i++;
	}
	return (0);
}
