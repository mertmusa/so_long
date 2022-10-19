/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel42.tr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:45:30 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/01 16:18:44 by mtemel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)b;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return ((void *)t);
}
/*
#include<string.h>
#include<stdio.h>
int main()
{
	char	ptr[] = "mterfdsfsfafa";
	printf("%s\n", ft_memset(ptr, 65, sizeof(ptr)));
	printf("%s\n", ptr);
	printf("%s\n", memset(ptr, 65, sizeof(ptr)));
	printf("%s\n", ptr);
}
*/
