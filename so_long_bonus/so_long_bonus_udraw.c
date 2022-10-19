/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_udraw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:32:20 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/10 17:49:44 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ber_to_map(t_data *map)
{
	int	fd;
	int	d_y;

	d_y = 0;
	fd = open(map->fname, O_RDONLY);
	if (fd < 0)
		error_printf("No file and/or directory", map);
	map->tdm = malloc((line_count(map) + 1) * sizeof(char *));
	if (!map->tdm)
		error_printf("Empty map", map);
	while (d_y < line_count(map))
	{
		map->tdm[d_y] = get_next_line(fd);
		write (1, map->tdm[d_y], ft_strlen(map->tdm[d_y]));
		d_y++;
	}
	map->tdm[d_y] = NULL;
	close(fd);
	check_map(map);
}

int	itis_ber(char *str)
{
	if (ft_strlen(str) < 5)
		return (0);
	if (ft_strncmp(".ber", (str + ft_strlen(str) - 4), 4) != 0)
		return (0);
	return (1);
}

void	image_draw(t_data *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, image, x * 32, y * 32);
}

void	add_image(t_data *game)
{
	game->tree = mlx_xpm_file_to_image(game->mlx,
			"xpm/tree/t1.xpm", &game->w, &game->h);
	game->gate = mlx_xpm_file_to_image(game->mlx,
			"xpm/gate/tile000.xpm", &game->w, &game->h);
	game->champion = mlx_xpm_file_to_image(game->mlx,
			"xpm/character/31.xpm", &game->w, &game->h);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"xpm/ctrl_pnl/tile000.xpm", &game->w, &game->h);
	game->background = mlx_xpm_file_to_image(game->mlx,
			"xpm/ground_black.xpm", &game->w, &game->h);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"xpm/tree/t4.xpm", &game->w, &game->h);
}

void	put_xpm(t_data *game)
{
	int	i;
	int	j;

	add_action(game);
	i = -1;
	while (game->tdm[++i])
	{
		j = -1;
		while (game->tdm[i][++j])
		{
			if (game->tdm[i][j] == '1')
				image_draw(game, game->tree, j, i);
			if (game->tdm[i][j] == '0')
				image_draw(game, game->background, j, i);
			if (game->tdm[i][j] == 'P')
				image_draw(game, game->champion, j, i);
			if (game->tdm[i][j] == 'E')
				image_draw(game, game->gate, j, i);
			if (game->tdm[i][j] == 'C')
				image_draw(game, game->collect, j, i);
			if (game->tdm[i][j] == 'D')
				image_draw(game, game->enemy, j, i);
		}
	}
}
