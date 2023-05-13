/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:32:52 by aankote           #+#    #+#             */
/*   Updated: 2023/05/13 08:30:10 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

 int move_up(t_data *data)
{
    int x;
    int y;
    
    data->player.walk_dir = 1; 
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cos(data->player.routation_ang) * data->player.movestep + 6;
	y = data->player.py_pos + sin(data->player.routation_ang) * data->player.movestep + 6;
    if(data->map[y / CARE][x / CARE] != '1')
        update_walk(data);
    return (0);
}

int move_down(t_data *data)
{
    int x;
    int y;
    
    data->player.walk_dir = -1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cos(data->player.routation_ang) * data->player.movestep + 6;
	y = data->player.py_pos  + sin(data->player.routation_ang) * data->player.movestep + 6;
    if(data->map[y / CARE][x / CARE] != '1')
    {
        data->player.py_pos += 1;
        update_walk(data);
    }
    
    return (0);
}

int move_left(t_data *data)
{
    int x;
    int y;
    
    data->player.walk_dir = -1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cos(data->player.routation_ang + rad(90)) * data->player.movestep + P_SIZE;
	y = data->player.py_pos  + sin(data->player.routation_ang + rad(90))  * data->player.movestep + P_SIZE;
    if(data->map[y / CARE][x / CARE] != '1')
    {
        data->player.movestep = data->player.walk_dir * MOVE_SPEED;
        data->player.px_pos += cos(data->player.routation_ang + rad(90)) * data->player.movestep  ;
	    data->player.py_pos += sin(data->player.routation_ang + rad(90))  * data->player.movestep ;
        initializ(data);
    }
    return (0);
}

int move_right(t_data *data)
{
    int x;
    int y;
    
    data->player.walk_dir = 1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cos(data->player.routation_ang + rad(90)) * data->player.movestep + P_SIZE;
	y = data->player.py_pos  + sin(data->player.routation_ang + rad(90))  * data->player.movestep + P_SIZE;
    if(data->map[y / CARE][x / CARE] != '1')
    {
        data->player.movestep = data->player.walk_dir * MOVE_SPEED;
        data->player.px_pos += cos(data->player.routation_ang + rad(90)) * data->player.movestep;
	    data->player.py_pos += sin(data->player.routation_ang + rad(90))  * data->player.movestep;
        initializ(data);
    }
  
    return (0);
}
