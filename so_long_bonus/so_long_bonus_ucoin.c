/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_ucoin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:27:28 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/12 15:05:18 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	topcoin(t_data *game)
{
	game->tdm[game->p_y][game->p_x] = '0';
	game->tdm[game->p_y - 1][game->p_x] = 'P';
	game->g_move++;
	put_xpm(game);
	game->coin += 1;
}

void	leftcoin(t_data *game)
{
	game->tdm[game->p_y][game->p_x] = '0';
	game->tdm[game->p_y][game->p_x - 1] = 'P';
	game->g_move++;
	put_xpm(game);
	game->coin += 1;
}

void	downcoin(t_data *game)
{
	game->tdm[game->p_y][game->p_x] = '0';
	game->tdm[game->p_y + 1][game->p_x] = 'P';
	game->g_move++;
	put_xpm(game);
	game->coin += 1;
}

void	rightcoin(t_data *game)
{
	game->tdm[game->p_y][game->p_x] = '0';
	game->tdm[game->p_y][game->p_x + 1] = 'P';
	game->g_move++;
	put_xpm(game);
	game->coin += 1;
}
