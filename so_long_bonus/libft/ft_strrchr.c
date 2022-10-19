/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel42.tr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:13 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/03 13:53:04 by mtemel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ns;
	int		len;

	ns = (char *)str;
	len = ft_strlen(ns);
	while (len >= 0)
	{
		if (ns[len] == (unsigned char)c)
			return (ns + len);
		len --;
	}
	return (0);
}
