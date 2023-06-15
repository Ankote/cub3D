/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:40:42 by aankote           #+#    #+#             */
/*   Updated: 2023/06/15 10:44:59 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_dimensions(t_data *data)
{
    int x;
    int y;

    y = 0;
	while(data->map[y])
	{
		x = 0;  
		while(data->map[y][x])
			x ++;
		y++;
	}
	 data->win.map_x = x * CARE;
	 data->win.map_y = y * CARE;
}

void get_player_pos(t_data *data)
{
	int x;
	int y;
	
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if(is_player(data->map[y][x])) 
				break;
			x ++;
		}
		if(is_player(data->map[y][x])) 
			break;
		y ++;
	}
	if(data->map[y][x] == 'N')
		data->player.routation_ang =  rad(270);
	if(data->map[y][x] == 'S')
		data->player.routation_ang =  rad(90);
	if(data->map[y][x] == 'E')
		data->player.routation_ang =  rad(0);
	if(data->map[y][x] == 'W')
		data->player.routation_ang =  rad(180);
	data->player.turn_dir = 0;
	data->player.px_pos = x * CARE;
	data->player.py_pos = y * CARE;
}

double rad(double deg)
{
	return (deg * PI / 180);
}

double deg(double rad)
{
	return (rad * 180  / PI);
}