/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel42.tr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:26:21 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/03 12:44:47 by mtemel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	c;
	size_t	retval;

	lensrc = 0;
	lendst = 0;
	c = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	while (dst[lendst] != '\0')
		lendst++;
	if (size == 0)
		return (lensrc);
	else if (size < lendst)
		retval = lensrc + size;
	else
		retval = lensrc + lendst;
	while (src[c] != '\0' && (lendst + c) < (size - 1))
	{
		dst[lendst + c] = src [c];
		c++;
	}
	dst[lendst + c] = '\0';
	return (retval);
}
