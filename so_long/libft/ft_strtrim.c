/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:56:05 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/08 13:18:32 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ctrl(char c, char const *trim)
{
	int	s;

	s = 0;
	while (trim[s] != 0)
	{
		if (trim[s] == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	lenstr;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	lenstr = ft_strlen(s1);
	while (s1[i] != '\0' && ctrl(s1[i], set))
		i++;
	while (lenstr > i && ctrl(s1[lenstr - 1], set))
		lenstr--;
	res = (char *)malloc(sizeof(char) * ((lenstr - i) + 1));
	if (!res)
		return (0);
	while (i < lenstr)
		res[j++] = (char)s1[i++];
	res[j] = '\0';
	return (res);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	printf("%s\n", ft_strtrim("123", ""));
	//printf("%s\n", strtrim("abcdba", "acb"));
}*/
