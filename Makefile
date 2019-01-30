# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 11:26:39 by lubernar          #+#    #+#              #
#    Updated: 2019/01/30 11:36:54 by lubernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC = ./srcs/draw_map.c ./srcs/fdf.c ./srcs/get_next_line.c ./srcs/read_map.c

all: $(NAME)

$(NAME) :
	cd libft ; $(MAKE) -f Makefile
	$(CC) $(CFLAG) $(NAME) $(SRC) libft/libft.a -L /usr/local/lib/ -lmlx -framewowrk OpenGL -framewowrk AppKit

clean :
	cd libft ; $(MAKE) -f Makefile clean


fclean :
	rm -f $(NAME)
	cd libft ; $(MAKE) -f Makefile fclean

re : fclean all
