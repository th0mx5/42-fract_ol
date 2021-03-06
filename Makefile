# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 00:25:16 by thbernar          #+#    #+#              #
#    Updated: 2018/03/13 15:37:56 by thbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  fts_utils.c \
	  fts_draw.c \
	  fts_map.c \
	  fts_fractales.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx
	mv libft/libft.a .
	mv minilibx/libmlx.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	gcc -Wall -g -Werror -Wextra -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
	make -C libft clean
	make -C minilibx clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	make -C minilibx clean
	rm -rf $(NAME)

re : fclean all
