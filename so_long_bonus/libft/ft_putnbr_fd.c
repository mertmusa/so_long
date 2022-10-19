/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:17:54 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/08 17:47:56 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, &"-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(fd, &"-", 1);
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr((nb / 10), fd);
	}
	if (nb < 10)
	{
		nb = nb + 48;
		write(fd, &nb, 1);
		return ;
	}
	nb = nb % 10 + 48;
	write (fd, &nb, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

/*
#include<stdio.h>
#include<fcntl.h>
int main ()
{
	int c = -123234567;
	int i = open("tempdesk.txt", O_WRONLY);
	ft_putnbr_fd(c, i);
}
*/
