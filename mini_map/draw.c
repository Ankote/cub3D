/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:36:56 by aankote           #+#    #+#             */
/*   Updated: 2023/05/07 18:37:49 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int initializ(t_data *data)
{
    draw_map(data);
    draw_lines(data);
    draw_player(data, data->px_pos, data->py_pos);
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->img.img, 0, 0);
    return (0);
}

void create_map(t_data *data)
{
	t_img	img;
	
	img.img = mlx_new_image(data->win.mlx, MAP_X, MAP_Y);
	data->img = img;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	data->px_pos = 300;
    data->py_pos = 200;
	initializ(data);
}