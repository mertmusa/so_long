/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:05:31 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/19 03:35:10 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_data {
	char	*fname;
	void	*mlx;
	void	*mlx_win;
	void	*champion;
	void	*tree;
	void	*background;
	void	*collect;
	void	*gate;
	void	*enemy;
	char	**tdm;
	int		xmax;
	int		ymax;
	int		w;
	int		h;
	int		g_coin;
	int		g_move;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		fe_y;
	int		coin;
	int		index;
	int		isway;
}				t_data;

int		hookfunc(t_data *game);
int		push_button(int keycode, t_data *game);
int		closescreen(t_data *game);
void	turnright(t_data *game);
void	turndown(t_data *game);
void	turnup(t_data *game);
void	turnleft(t_data *game);
void	player(t_data *game);
void	let_the_game_begin(t_data *game);
void	counter_coin(t_data *map);
void	first_value(t_data *game);
void	check_map(t_data *map);
int		line_count(t_data *map);
int		column_count(t_data *map);
void	win_printf(char *str, t_data *map);
void	error_printf(char *str, t_data *map);
void	error_printf_g(char *str);
void	move_enemy(t_data *game, int index);
void	move_enemy2(t_data *game);
void	find_enemy(t_data *game);
void	put_xpm(t_data *game);
void	add_image(t_data *game);
void	image_draw(t_data *game, void *image, int x, int y);
int		itis_ber(char *str);
void	ber_to_map(t_data *map);
void	rightcoin(t_data *game);
void	downcoin(t_data *game);
void	leftcoin(t_data *game);
void	topcoin(t_data *game);
void	iscollectible(t_data *map);
void	isduplicate(t_data *map);
void	iswalltrue(t_data *map);
void	ismaptrue(t_data *map);
void	isrectangular(t_data *map);
void	add_action(t_data *game);
int		addanimation5(t_data *game, int index);
int		addanimation3(t_data *game, int index);
int		addanimation2(t_data *game, int index);
int		addanimation(t_data *game, int index);
void	pathfind(t_data *map);
void	pathnumber(t_data *map, int dy, int dx);
void	pathfindrec(t_data *map, int dy, int dx, int **mapint);

#endif
