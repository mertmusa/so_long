# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 13:54:07 by mtemel            #+#    #+#              #
#    Updated: 2022/10/10 18:03:07 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	cd mlx && make
	cd libft && make
	@make -C ft_printf
	gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit ft_printf/libftprintf.a libft/libft.a so_long_bonus*.c -o so_long_bonus

clean:
	cd mlx && make clean
	cd libft && make clean
	cd ft_printf && make clean
	rm -f so_long_bonus

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean

re: fclean all

.PHONY: all clean fclean re bonus
