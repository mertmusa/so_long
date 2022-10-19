/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_uplay.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:35:21 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/19 03:40:11 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map(t_data *map)
{
	isrectangular(map);
	ismaptrue(map);
	iswalltrue(map);
	isduplicate(map);
	iscollectible(map);
	player(map);
	pathfind(map);
}

void	first_value(t_data *game)
{
	game -> tdm = NULL;
	game -> champion = NULL;
	game ->tree = NULL;
	game -> background = NULL;
	game -> collect = NULL;
	game -> gate = NULL;
	game -> ymax = line_count(game);
	game -> xmax = column_count(game);
	game -> w = 32;
	game -> h = 32;
	game -> g_coin = 0;
	game -> coin = 0;
	game -> g_move = 0;
	game -> index = 0;
}

/*void	counter_coin(t_data *map)
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
}
//counter_coin(game); let_the_game_begin func. last line
*/

void	let_the_game_begin(t_data *game)
{
	int	fd;

	fd = open(game->fname, O_RDONLY);
	if (fd < 0)
		error_printf("No file and/or directory", game);
	close(fd);
	ber_to_map(game);
	put_xpm(game);
}
