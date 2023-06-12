# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aankote <aankote@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 10:42:23 by aankote           #+#    #+#              #
#    Updated: 2023/06/12 15:18:26 by aankote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILES = cub3d.c events.c movements/move.c \
		read_map.c mini_map/draw.c mini_map/draw_utils0.c mini_map/draw_utils01.c mini_map/draw_utils02.c \
		mini_map/check_hor.c mini_map/check_ver.c mini_map/check_intersictions.c window/main_window.c \
		window/main_utils.c

OBJCS = $(FILES:.c=.o)

INCLUDES = get_next_line/get_next_line.a libft/libft.a
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit -static-libsan -fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

$(NAME) : $(OBJCS)
	@echo "\n"
	@make -C libft
	@make -C get_next_line
	@echo "\033[0;32mCompiling cub3D..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(FRAMEWORK) $(OBJCS) -o $(NAME) $(INCLUDES)

clean :
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@make clean -C get_next_line/
	@echo "\nRemoving binaries..."
	rm -fr $(OBJCS)

fclean : clean
	@make fclean -C libft/
	@make fclean -C get_next_line/
	@echo "\nDeleting objects..."
	@echo "\nDeleting executable..."
	rm -fr $(NAME)

re : fclean all

run : all clean

push : fclean
	git add .
	git commit -m "UPDATED"
	git push
	