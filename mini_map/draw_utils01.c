/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:40:42 by aankote           #+#    #+#             */
/*   Updated: 2023/05/24 11:15:44 by aankote          ###   ########.fr       */
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