/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:28:28 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/10 17:14:56 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = 0;
	}
	if (!s1 && !s2)
		return (0);
	ns = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ns)
		return (0);
	if (s1)
		while (*(s1 + j))
			*(ns + i++) = *(s1 + j++);
	j = 0;
	while (*(s2 + j))
		*(ns + i++) = *(s2 + j++);
	*(ns + i) = '\0';
	free(s1);
	return (ns);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "ilkmetin";
	char s2[] = "-ikincimetin";
	printf("%s\n",ft_strjoin(s1, s2));
}
*/
