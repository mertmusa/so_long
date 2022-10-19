/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_uexit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:42:33 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/10 16:56:22 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_printf_g(char *str)
{
	ft_printf("Error: %s\n", str);
	exit (EXIT_FAILURE);
}

void	error_printf(char *str, t_data *map)
{
	ft_printf("Error: %s\n", str);
	free(map->tdm);
	free(map);
	exit (EXIT_FAILURE);
}

void	win_printf(char *str, t_data *map)
{
	ft_printf("%s\n", str);
	free(map->tdm);
	free(map);
	exit (EXIT_SUCCESS);
}

int	column_count(t_data *map)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = open(map->fname, O_RDONLY);
	line = get_next_line(fd);
	ret = ft_strlen(line) - 1;
	free(line);
	close(fd);
	return (ret);
}

int	line_count(t_data *map)
{
	int		fdmap;
	char	c;
	int		ret;

	ret = 0;
	fdmap = open(map->fname, O_RDONLY);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '\n'))
			ret++;
	}
	close(fdmap);
	return (ret);
}
