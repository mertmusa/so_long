/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel42.tr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:51:13 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/03 17:42:05 by mtemel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*s1;
	char		*s2;
	size_t		i;
	size_t		j;
	size_t		s2len;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	s2len = ft_strlen(s2);
	if (s2[0] == '\0')
		return (s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s2[j] == s1[i + j] && (i + j) < len)
			j++;
		if (j == s2len)
			return (s1 + i);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char s1[] = "aaabcabcd";
	//printf("%s\n", strnstr(s1, "cd", 8));
	printf("%s\n", ft_strnstr(s1, "cd", 8));
}*/
