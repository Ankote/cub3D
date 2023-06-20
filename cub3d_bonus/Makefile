# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aankote <aankote@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 10:42:23 by aankote           #+#    #+#              #
#    Updated: 2023/06/20 10:56:48 by aankote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D_bonus

FILES = cub3d_bonus.c events_bonus.c movements/move_bonus.c \
		builting/draw_bonus.c builting/draw_utils0_bonus.c\
		 builting/draw_utils01_bonus.c builting/draw_utils02_bonus.c \
		builting/check_hor_bonus.c builting/check_ver_bonus.c\
		 builting/check_intersictions_bonus.c window/main_window_bonus.c \
		parse/parse_bonus.c parse/extensions_bonus.c \
		parse/checks_bonus.c parse/textures_bonus.c parse/checks1_bonus.c\
		parse/vulnerabilities_bonus.c builting/textures_bonus.c mini_map/mini_map_bonus.c

OBJCS = $(FILES:.c=.o)

INCLUDES = get_next_line/get_next_line.a libft/libft.a
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit -static-libsan

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

CC = cc

bonus : $(NAME)

$(NAME) : $(OBJCS)
	@echo "\n"
	@make -C libft
	@make -C get_next_line
	@echo "\033[0;32mCompiling cub3D..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(FRAMEWORK) $(OBJCS) -o $(NAME)


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

re : fclean bonus
