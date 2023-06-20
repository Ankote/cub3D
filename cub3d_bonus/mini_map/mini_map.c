/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:12:05 by aankote           #+#    #+#             */
/*   Updated: 2023/06/20 10:22:09 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_player(t_data *data)
{
	int	x;
	int	y;

	y = MAP_Y / 2;
	while (y < MAP_Y / 2 + P_SIZE)
	{
		x = MAP_X / 2;
		while (x < MAP_X / 2 + P_SIZE)
			my_mlx_pixel_put(&data->main_img, x++, y, RED);
		y ++;
	}
	return (0);
}

void	draw_map(t_data *data, int x, int y)
{
	int	mx;
	int	my;

	my = (data->player.py_pos / 4 - MAP_Y / 2) - 8;
	y = -1;
	while (++y < MAP_Y)
	{
		x = -1;
		mx = (data->player.px_pos / 4 - MAP_X / 2) - 8;
		while (++x < MAP_X)
		{
			if ((mx + 8) / 16 >= 0 && (my + 8) / 16 >= 0 && (mx + 8)
				< data->win.map_x / 4 && (my + 8) < data->win.map_y / 4)
			{
				if (data->map->map_copy[(my + 8) / 16][(mx + 8) / 16] == '1')
					my_mlx_pixel_put(&data->main_img, x, y, WALL);
				else
					my_mlx_pixel_put(&data->main_img, x, y, 0xF1F1C1);
			}
			else
				my_mlx_pixel_put(&data->main_img, x, y, 0xF1F1C1);
			(mx)++;
		}
		my ++;
	}
}
