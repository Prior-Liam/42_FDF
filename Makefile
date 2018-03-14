# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 12:19:27 by lprior            #+#    #+#              #
#    Updated: 2018/03/13 19:48:16 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./libft/

header = fdf.h

includes = ./libft/libft.a

SRC = main.c ft_initialize.c ft_lists.c

OBJ = *.o

cc = @gcc

name = fdf

all : $(name)

$(name) :
	@make -C libft/
	$(cc) $(libx_flags) $(SRC) $(includes) -o $(name)
	@echo "Created FDF executable"
clean:
	@make -C libft/ clean
	@/bin/rm -f $(name)
fclean: clean
	@make -C libft/ fclean
re: fclean all