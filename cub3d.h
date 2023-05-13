/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:40:06 by aankote           #+#    #+#             */
/*   Updated: 2023/05/13 08:11:05 by aankote          ###   ########.fr       */
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

# define WIN_X 1000
# define WIN_Y 640
# define CARE 16
# define P_SIZE 6
# define MAP_X 320
# define MAP_Y 224

/********************COLORS*****************/
# define WAY 0x00CDB82F
# define PLAYER 0x00CAF5FA
# define LINE 0x00AFAD9D
# define WALL 0x00330019
# define WALL 0x00330019
# define SKY 0x00C4F6FC
# define FLOOR 0x0093FFBE
# define RED 0x00FF0000
/**********MATH****************************/
# define PI 3.14159265359
# define MOVE_SPEED 5
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int 	map_x;
	int		map_y;
}	t_win;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}
			t_img;
typedef struct  s_player
{
	int px_pos;
	int py_pos;
	int walk_dir; 
	int turn_dir;
	int rot_dir;
	double movestep;
	double routation_ang;
	
} t_player;

typedef struct s_data
{
	char **map;
	t_win win;
	t_img img;
	t_player player;
}	t_data;


int				ft_exit(void *key);
int				ft_key_hook(int key, t_data *data);
int				draw_squart(t_data *data ,int x, int y);
int				draw_lines(t_data *data);
int				draw_player(t_data *data, int x_pos, int y_pos);
int				replace_player(t_data *data, int x_pos, int y_pos);
int				draw_map(t_data *data);

/*************movements************************/
int				move_down(t_data *data);
int				move_up(t_data *data);
int				move_left(t_data *data);
int				move_right(t_data *data);

/****************Read map****************/
char	**split_map(int fd);

/*****************Draw msp***************/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	create_map(t_data *data);
int		initializ(t_data *data);
void	get_dimensions(t_data *data);
void get_player_pos(t_data *data);
int is_player(int c);
int create_window(t_win *win, t_data *data);
void draw_win();void draw_sky(t_img *img);
 void draw_rays(t_data *data);
 double rad(double deg);
int update_turn(t_data *data);
int update_walk(t_data *data);
# endif