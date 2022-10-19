/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel42.tr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:55:49 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/05 16:55:34 by mtemel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
		return (0);
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
