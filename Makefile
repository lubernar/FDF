# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 11:26:39 by lubernar          #+#    #+#              #
#    Updated: 2019/02/08 10:19:15 by lubernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC = ./srcs/draw_map.c ./srcs/draw_line.c ./srcs/get_next_line.c \
	  ./srcs/read_map.c ./srcs/text.c ./srcs/main.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECT)
	cd libft ; $(MAKE) -f Makefile
	$(MAKE) -C minilibx_macos
	$(CC) -o $(NAME) $(CFLAG) $(SRC) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean :
	@cd libft ; $(MAKE) -f Makefile clean


fclean :
	rm -f $(NAME)
	rm -f $(OBJECT)
	@cd libft ; $(MAKE) -f Makefile clean

re : fclean all

.PHONY: all clean fclean
