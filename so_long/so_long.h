/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:05:31 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/19 00:10:22 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_direction {
	int	up;
	int	down;
	int	right;
	int	left;
}				t_dirct;

typedef struct s_xyscores {
	int	g;
	int	h;
	int	f;
	int	x;
	int	y;
}				t_xyscores;

typedef struct s_data {
	char	*fname;
	void	*mlx;
	void	*mlx_win;
	void	*champion;
	void	*tree;
	void	*background;
	void	*collect;
	void	*gate;
	char	**tdm;
	int		xmax;
	int		ymax;
	int		w;
	int		h;
	int		g_coin;
	int		g_move;
	int		p_x;
	int		p_y;
	int		coin;
	int		isway;
	t_dirct	dir;
}				t_data;

int		push_button(int keycode, t_data *game);
void	turnright(t_data *game);
void	turndown(t_data *game);
void	turnup(t_data *game);
void	turnleft(t_data *game);
void	player(t_data *game);
void	rightcoin(t_data *game);
void	downcoin(t_data *game);
void	leftcoin(t_data *game);
void	topcoin(t_data *game);
int		closescreen(t_data *game);
void	let_the_game_begin(t_data *game);
void	counter_coin(t_data *map);
void	put_xpm(t_data *game);
void	add_image(t_data *game);
void	image_draw(t_data *game, void *image, int x, int y);
void	first_value(t_data *game);
int		itis_ber(char *str);
void	ber_to_map(t_data *map);
void	check_map(t_data *map);
void	iscollectible(t_data *map);
void	isduplicate(t_data *map);
void	iswalltrue(t_data *map);
void	ismaptrue(t_data *map);
void	isrectangular(t_data *map);
int		line_count(t_data *map);
int		column_count(t_data *map);
void	win_printf(char *str, t_data *map);
void	error_printf(char *str, t_data *map);
void	error_printf_g(char *str);
void	pathfind(t_data *map);
void	pathfindrec(t_data *map, int dy, int dx, int **mapint);
void	pathnumber(t_data *map, int dy, int dx);

#endif
