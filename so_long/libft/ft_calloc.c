/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel42.tr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:52:03 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/05 16:54:29 by mtemel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(sizeof(char) * (count * size));
	if (!ptr)
		return (NULL);
	while (i < (size * count))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
