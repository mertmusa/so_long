/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_uanimation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:28:54 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/10 17:52:30 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	addanimation(t_data *game, int index)
{
	if (index % 6 == 1)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				"xpm/ctrl_pnl/tile000.xpm", &game->w, &game->h);
	if (index % 6 == 2)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				"xpm/ctrl_pnl/tile003.xpm", &game->w, &game->h);
	if (index % 6 == 3)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				"xpm/ctrl_pnl/tile006.xpm", &game->w, &game->h);
	if (index % 6 == 4)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				"xpm/ctrl_pnl/tile009.xpm", &game->w, &game->h);
	if (index % 6 == 5)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				"xpm/ctrl_pnl/tile012.xpm", &game->w, &game->h);
	if (index % 6 == 0)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				"xpm/ctrl_pnl/tile015.xpm", &game->w, &game->h);
	return (0);
}

int	addanimation2(t_data *game, int index)
{
	if (index % 6 == 1)
		game->champion = mlx_xpm_file_to_image(game->mlx,
				"xpm/character/31.xpm", &game->w, &game->h);
	if (index % 6 == 2)
		game->champion = mlx_xpm_file_to_image(game->mlx,
				"xpm/character/32.xpm", &game->w, &game->h);
	if (index % 6 == 3)
		game->champion = mlx_xpm_file_to_image(game->mlx,
				"xpm/character/33.xpm", &game->w, &game->h);
	if (index % 6 == 4)
		game->champion = mlx_xpm_file_to_image(game->mlx,
				"xpm/character/34.xpm", &game->w, &game->h);
	if (index % 6 == 5)
		game->champion = mlx_xpm_file_to_image(game->mlx,
				"xpm/character/35.xpm", &game->w, &game->h);
	if (index % 6 == 0)
		game->champion = mlx_xpm_file_to_image(game->mlx,
				"xpm/character/36.xpm", &game->w, &game->h);
	return (0);
}

int	addanimation3(t_data *game, int index)
{
	if (index % 6 == 1)
		game->gate = mlx_xpm_file_to_image(game->mlx,
				"xpm/gate/tile000.xpm", &game->w, &game->h);
	if (index % 6 == 2)
		game->gate = mlx_xpm_file_to_image(game->mlx,
				"xpm/gate/tile001.xpm", &game->w, &game->h);
	if (index % 6 == 3)
		game->gate = mlx_xpm_file_to_image(game->mlx,
				"xpm/gate/tile002.xpm", &game->w, &game->h);
	if (index % 6 == 4)
		game->gate = mlx_xpm_file_to_image(game->mlx,
				"xpm/gate/tile003.xpm", &game->w, &game->h);
	if (index % 6 == 5)
		game->gate = mlx_xpm_file_to_image(game->mlx,
				"xpm/gate/tile004.xpm", &game->w, &game->h);
	if (index % 6 == 0)
		game->gate = mlx_xpm_file_to_image(game->mlx,
				"xpm/gate/tile005.xpm", &game->w, &game->h);
	return (0);
}

int	addanimation5(t_data *game, int index)
{
	if (index % 3 == 1)
		game->tree = mlx_xpm_file_to_image(game->mlx,
				"xpm/tree/t1.xpm", &game->w, &game->h);
	if (index % 3 == 2)
		game->tree = mlx_xpm_file_to_image(game->mlx,
				"xpm/tree/t2.xpm", &game->w, &game->h);
	if (index % 3 == 0)
		game->tree = mlx_xpm_file_to_image(game->mlx,
				"xpm/tree/t3.xpm", &game->w, &game->h);
	return (0);
}

void	add_action(t_data *game)
{
	add_image(game);
	addanimation(game, game->index);
	addanimation2(game, game->index);
	addanimation3(game, game->index);
	addanimation5(game, game->index);
}
