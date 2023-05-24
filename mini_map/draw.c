/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:36:56 by aankote           #+#    #+#             */
/*   Updated: 2023/05/23 20:42:27 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int update_walk(t_data *data)
{
	data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	data->player.px_pos += cos(data->player.routation_ang) * data->player.movestep;
	data->player.py_pos += sin(data->player.routation_ang) * data->player.movestep;
	initializ(data);
	return (0);
}


int update_turn(t_data *data)
{
	data->player.routation_ang += MOVE_SPEED * rad(data->player.turn_dir);
	data->player.ray_angle = data->player.routation_ang - rad(30);
	initializ(data);
	return (0);
}
void    angle_adjust(double *ray_angle){
    *ray_angle = fmod(*ray_angle , (2 * PI));
    if(*ray_angle < 0)
        *ray_angle = (2 * PI) + *ray_angle;
}

int initializ(t_data *data)
{
	if(data->player.routation_ang >= 3 * PI || data->player.routation_ang <= -3 * PI)
	{
		printf("tfoooo\n");
		data->player.routation_ang = PI;
	}
	// angle_adjust(&data->player.routation_ang);
    draw_map(data);
    draw_lines(data);
    draw_player(data, data->player.px_pos, data->player.py_pos);
	draw_rays(data);
	draw_p_dir(data);
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->img.img, 0, 0);
    return (0);
}

void create_map(t_data *data)
{
	t_img	img;
	
	img.img = mlx_new_image(data->win.mlx, data->win.map_x, data->win.map_y);
	data->img = img;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	get_player_pos(data);
	initializ(data);
}
