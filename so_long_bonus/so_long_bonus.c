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

#include "so_long_bonus.h"

int	closescreen(t_data *game)
{
	win_printf("The game is closed!", game);
	return (EXIT_FAILURE);
}

int	push_button(int keycode, t_data *game)
{
	if (keycode == 53)
	{
		write(1, "Game is closed with ESC", 14);
		mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->tdm);
		free(game);
		exit(0);
	}
	if (keycode == 0)
		turnleft(game);
	else if (keycode == 13)
		turnup(game);
	else if (keycode == 1)
		turndown(game);
	else if (keycode == 2)
		turnright(game);
	return (0);
}

int	hookfunc(t_data *game)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = ft_itoa(game->g_move);
	game->index++;
	while (j < 10)
	{
		while (i < 50000000)
			i++;
		j++;
	}
	move_enemy(game, game->index);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_string_put(game->mlx, game->mlx_win,
		column_count(game) * 32, 10, 0x0000FF00, "Move:");
	mlx_string_put(game->mlx, game->mlx_win,
		(column_count(game) * 32), 20, 0x0000FF00, s);
	put_xpm(game);
	free(s);
	return (0);
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
			column_count(game) * 32 + 34, line_count(game) * 32, "so_long");
	first_value(game);
	let_the_game_begin(game);
	mlx_loop_hook(game->mlx, hookfunc, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, push_button, game);
	mlx_hook(game->mlx_win, 17, 1L << 5, closescreen, game);
	mlx_loop(game->mlx);
	free(game->tdm);
	free(game);
}
