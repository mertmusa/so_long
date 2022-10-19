/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_uenemy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:24:30 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/10 17:44:59 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tdm[i])
	{
		j = 0;
		while (game->tdm[i][j])
		{
			if (game->tdm[i][j] == 'D')
			{
				game->e_x = j;
				game->e_y = i;
			}
			j++;
		}
		i++;
	}
	game->fe_y = game->e_y;
}

void	move_enemy2(t_data *game)
{
	game->e_y = 1;
	if (game->tdm[game->e_y][game->e_x] == 'P')
		exit(0);
	game->tdm[game->e_y][game->e_x] = 'D';
	game->tdm[game->e_y - (game->e_y - game->fe_y)][game->e_x] = '0';
	put_xpm(game);
}

void	move_enemy(t_data *game, int index)
{
	find_enemy(game);
	if (game->tdm[game->e_y][game->e_x] == 'P')
		exit(0);
	if ((game->tdm[game->e_y + 1][game->e_x] == '0'
		|| game->tdm[game->e_y + 1][game->e_x] == 'P') && index % 10 == 8)
	{
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->background, game->e_x - 1, game->e_y - 1);
		game->tdm[game->e_y][game->e_x] = '0';
		if (game->tdm[game->e_y + 1][game->e_x] == 'P')
		{
			game->tdm[game->e_y + 1][game->e_x] = 'D';
			exit(0);
		}
		game->tdm[game->e_y + 1][game->e_x] = 'D';
		game->e_y++;
		put_xpm(game);
	}
	else if (game->tdm[game->e_y + 1][game->e_x] == '1'
		&& game->index % 10 == 8)
		move_enemy2(game);
}
