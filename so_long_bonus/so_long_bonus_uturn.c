/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_uturn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:26:48 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/12 15:24:02 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player(t_data *game)
{
	int	key;

	game->p_x = 0;
	game->p_y = 0;
	while (game -> tdm[game->p_y][game->p_x])
	{
		game->p_x = 0;
		while (game->tdm[game->p_y][game->p_x] != '\n')
		{
			if (game->tdm[game->p_y][game->p_x] == 'P')
				return ;
			game->p_x++;
		}
		game->p_y++;
	}
}

void	turnleft(t_data *game)
{
	player(game);
	if (game->tdm[game->p_y][game->p_x - 1] == '0')
	{
		game->tdm[game->p_y][game->p_x] = '0';
		game->tdm[game->p_y][game->p_x - 1] = 'P';
		game->g_move++;
		put_xpm(game);
	}
	else if (game->tdm[game->p_y][game->p_x - 1] == 'C')
		leftcoin(game);
	else if (game->tdm[game->p_y][game->p_x - 1] == 'E')
	{
		if (game->coin == game->g_coin)
		{
			win_printf("Congrats", game);
		}
		else
			ft_printf("Pls collect all collectables!\n");
	}
}

void	turnup(t_data *game)
{
	player(game);
	if (game->tdm[game->p_y - 1][game->p_x] == '0')
	{
		game->tdm[game->p_y][game->p_x] = '0';
		game->tdm[game->p_y - 1][game->p_x] = 'P';
		game->g_move++;
		put_xpm(game);
	}
	else if (game->tdm[game->p_y - 1][game->p_x] == 'C')
		topcoin(game);
	else if (game->tdm[game->p_y - 1][game->p_x] == 'E')
	{
		if (game->coin == game->g_coin)
		{
			win_printf("Congrats", game);
		}
		else
			ft_printf("Pls collect all collectables!\n");
	}
}

void	turndown(t_data *game)
{
	player(game);
	if (game->tdm[game->p_y + 1][game->p_x] == '0')
	{
		game->tdm[game->p_y][game->p_x] = '0';
		game->tdm[game->p_y + 1][game->p_x] = 'P';
		game->g_move++;
		put_xpm(game);
	}
	else if (game->tdm[game->p_y + 1][game->p_x] == 'C')
		downcoin(game);
	else if (game->tdm[game->p_y + 1][game->p_x] == 'E')
	{
		if (game->coin == game->g_coin)
		{
			win_printf("Congrats", game);
		}
		else
			ft_printf("Pls collect all collectables!\n");
	}
}

void	turnright(t_data *game)
{
	player(game);
	if (game->tdm[game->p_y][game->p_x + 1] == '0')
	{
		game->tdm[game->p_y][game->p_x] = '0';
		game->tdm[game->p_y][game->p_x + 1] = 'P';
		game->g_move++;
		put_xpm(game);
	}
	else if (game->tdm[game->p_y][game->p_x + 1] == 'C')
		rightcoin(game);
	else if (game->tdm[game->p_y][game->p_x + 1] == 'E')
	{
		if (game->coin == game->g_coin)
		{
			win_printf("Congrats", game);
		}
		else
			ft_printf("Pls collect all collectables!\n");
	}
}
