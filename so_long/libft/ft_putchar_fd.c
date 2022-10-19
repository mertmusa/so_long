/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:17:59 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/08 15:08:54 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
#include<stdio.h>
#include<fcntl.h>
int main ()
{
	char c = 'c';
	int i = open("tempdesk.txt", O_WRONLY);
	ft_putchar_fd(c, i);
}
*/
