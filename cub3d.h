/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:40:06 by aankote           #+#    #+#             */
/*   Updated: 2023/05/07 08:48:23 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
 #include <fcntl.h>

# define WIN_Y 640
# define WIN_X 1000
# define CARE 32
# define MAP_X 320
# define MAP_Y 224
# define WAY 0x00CDB82F
# define PLAYER 0x00CAF5FA
# define LINE 0x00AFAD9D

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
}	t_mlxk;

typedef struct s_data
{
	int px_pos;
	int py_pos;
	t_mlxk win;
}	t_data;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

int				ft_exit(void *key);
int				ft_key_hook(int key, t_data *data);
int				draw_squart(t_mlxk window ,int x, int y);
int				draw_lines(t_mlxk win);
int				draw_player(t_data *data, int x_pos, int y_pos);
int				replace_player(t_data *data, int x_pos, int y_pos);
int				draw_map(t_mlxk window);

/*************movements************************/
int				move_down(t_data *data);
int				move_up(t_data *data);
int				move_left(t_data *data);
int				move_right(t_data *data);

/****************Read map****************/
char	**split_map(int fd);

# endif