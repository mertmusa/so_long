/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:37:36 by mtemel            #+#    #+#             */
/*   Updated: 2022/02/08 12:44:23 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			pos;
	char		*s;

	pos = 1;
	i = 0;
	res = 0;
	s = (char *)str;
	while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
		i++;
	if (s[i] == '+' || s[i] == '-')
		pos = 1 - 2 * (s[i++] == '-');
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 +(s[i++] - 48);
		if (res > 2147483647 && pos == 1)
			return (-1);
		else if (res > 2147483648 && pos == -1)
			return (0);
	}
	return ((int)(res * pos));
}
/*
#include<stdio.h>
#include<stdlib.h>
int	main()
{
	char s[] = "   		-214748364854346787654345678765asd796tygnjdfk";
	printf("%d\n",ft_atoi(s));
	printf("%d\n",atoi(s));
}
*/
