/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:57:14 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/15 12:26:18 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*src;
	size_t	i;

	i = 0;
	src = (char *)s;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (0);
		*ret = '\0';
	}
	else
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (!ret)
			return (0);
		ft_strlcpy(ret, &src[start], len + 1);
	}
	return (ret);
}
/*
#include<stdio.h>
int main()
{
	printf("%s\n",ft_substr("tripouille", 1, 1));
}*/
