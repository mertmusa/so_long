/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:41:23 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/05 17:05:44 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->tdm = NULL;
	game->champion = NULL;
	game->tree = NULL;
	game->background = NULL;
	game->collect = NULL;
	game->gate = NULL;
	game->ymax = line_count(game);
	game->xmax = column_count(game);
	game->w = 32;
	game->h = 32;
	game->g_coin = 0;
	game->coin = 0;
	game->g_move = 0;
}

int	closescreen(t_data *game)
{
	win_printf("The game is closed!", game);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data	*game;

	if (argc != 2 || !itis_ber(argv[1]))
		error_printf_g("Wrong format or argument error!");
	game = (t_data *)malloc(sizeof(t_data));
	game->fname = ft_strdup(argv[1]);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window (game->mlx,
			column_count(game) * 32, line_count(game) * 32, "so_long");
	first_value(game);
	let_the_game_begin(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, push_button, game);
	mlx_hook(game->mlx_win, 17, 1L << 5, closescreen, game);
	mlx_loop(game->mlx);
	free(game->tdm);
	free(game);
}
