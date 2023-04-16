/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:55:26 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/14 17:19:31 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;
	int	nb_devided;

	mod = 0;
	nb_devided = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		mod = n % 10;
		nb_devided = n / 10;
		ft_putnbr_fd(nb_devided, fd);
	}
	if (n > 9)
		ft_putchar_fd(mod + '0', fd);
	else
		ft_putchar_fd(n + '0', fd);
}
