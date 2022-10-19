/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:13 by mtemel            #+#    #+#             */
/*   Updated: 2022/09/27 12:39:05 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char s[] = "tripouille";
	printf("%s\n", strchr(s, 't' + 256));
	printf("%s\n", ft_strchr(s, 't' + 256));
	printf("%c\n", 't' + 256);
}*/
