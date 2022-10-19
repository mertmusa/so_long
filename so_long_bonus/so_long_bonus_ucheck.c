/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_ucheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:30:09 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/12 15:17:43 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	isrectangular(t_data *map)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (map->tdm[i])
	{
		j = 0;
		while (map->tdm[i][j])
			j++;
		if (i != 0 && j != temp)
			error_printf("Map is not rectangular!", map);
		temp = j;
		i++;
	}
}

void	ismaptrue(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tdm[i])
	{
		j = 0;
		while (map->tdm[i][j])
		{
			if (map->tdm[i][j] == 'E' || map->tdm[i][j] == 'C'
				|| map->tdm[i][j] == 'P' || map->tdm[i][j] == '1'
				|| map->tdm[i][j] == '0' || map->tdm[i][j] == '\n'
				|| map->tdm[i][j] == 'D')
				j++;
			else
				error_printf("Map is not true!", map);
		}
		i++;
	}
}

void	iswalltrue(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	map->ymax = line_count(map);
	map->xmax = column_count(map);
	while (map->tdm[i])
	{
		j = 0;
		while (j < map->xmax - 1)
		{
			if (map->tdm[0][j] != '1' || map->tdm[i][0] != '1')
				error_printf("Walls are not true 1!", map);
			if (map->tdm[map->ymax - 1][j] != '1'
				|| map->tdm[i][map->xmax - 1] != '1')
				error_printf("Walls are not true 2!", map);
			j++;
		}
		i++;
	}
}

void	isduplicate(t_data *map)
{
	int	i;
	int	j;
	int	p_counter;
	int	e_counter;

	i = 0;
	p_counter = 0;
	e_counter = 0;
	while (map->tdm[i])
	{
		j = 0;
		while (map->tdm[i][j])
		{
			if (map->tdm[i][j] == 'P')
				p_counter++;
			if (map->tdm[i][j] == 'E')
				e_counter++;
			j++;
		}
		i++;
	}
	if (p_counter <= 0 || p_counter >= 2 || e_counter <= 0 || e_counter >= 2)
		error_printf("Gate or champion error!", map);
}

void	iscollectible(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tdm[i])
	{
		j = 0;
		while (map->tdm[i][j])
		{
			if (map->tdm[i][j] == 'C')
				map->g_coin++;
			j++;
		}
		i++;
	}
	if (map->g_coin <= 0)
		error_printf("No coin on the map!", map);
}
