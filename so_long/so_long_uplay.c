/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_uplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:46:36 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/12 15:23:52 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	itis_ber(char *str)
{
	if (ft_strlen(str) < 5)
		return (0);
	if (ft_strncmp(".ber", (str + ft_strlen(str) - 4), 4) != 0)
		return (0);
	return (1);
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
	ft_printf("Number of move(s): %d\n", game->g_move);
	return (0);
}
