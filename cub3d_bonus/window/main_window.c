/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:12:50 by aankote           #+#    #+#             */
/*   Updated: 2023/06/19 16:30:05 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_window(t_win *win, t_data *data)
{
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, WIN_X,
			WIN_Y, "SAIYANS cub3D");
	data->win = *win;
	return (0);
}

void	draw_sky(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_Y / 2)
	{
		x = 0;
		while (x < WIN_X)
			my_mlx_pixel_put(&data->main_img,
				x ++, y, data->wall.ceiling_color);
		y ++;
	}
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	y = WIN_Y / 2;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
			my_mlx_pixel_put(&data->main_img,
				x ++, y, data->wall.floor_color);
		y ++;
	}
}

void	draw_win(t_data *data)
{
	draw_sky(data);
	draw_floor(data);
	draw_things(data);
	mlx_put_image_to_window(data->win.mlx,
		data->win.mlx_win, data->main_img.img, 0, 0);
	mlx_clear_window(data->win.mlx, data->win.mlx_win);
}
