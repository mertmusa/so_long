# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 10:46:01 by mtemel            #+#    #+#              #
#    Updated: 2022/09/27 12:26:31 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = $(shell find . -type f ! -name "ft_lst*.c" -name "*.c")

BSRCS = ft_lst*.c

OBJ = $(SRCS:.c=.o)

BOBJ = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJ)

bonus: $(NAME)
	gcc $(FLAGS) $(BSRCS)
	ar rcs $(NAME) $(BOBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re:	fclean all

.PHONY: all bonus clean fclean re
