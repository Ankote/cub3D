/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersictions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:10:35 by aankote           #+#    #+#             */
/*   Updated: 2023/06/10 16:46:20 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_intersictions(t_data *data)
{
    double hor_line;
    double ver_line;
    double x;
    double y;
    
    hit_hor_wall(data);
    hit_ver_wall(data);
    data->cords.hor_dx = data->cords.xb_hor - data->player.px_pos;
    data->cords.hor_dy = data->cords.yb_hor - data->player.py_pos;
    data->cords.ver_dx = data->cords.xb_ver - data->player.px_pos;
    data->cords.ver_dy = data->cords.yb_ver - data->player.py_pos;
    hor_line = sqrt(pow(data->cords.hor_dx, 2) + pow(data->cords.hor_dy, 2));
    ver_line = sqrt(pow(data->cords.ver_dx, 2) + pow(data->cords.ver_dy, 2));

    if(hor_line <= ver_line)
    {
        x = data->cords.xb_hor;
        y = data->cords.yb_hor;
    }
    else
    {
        x = data->cords.xb_ver;
        y = data->cords.yb_ver;
    }
    draw_ray(data, x , y, RED);
}


void draw_rays(t_data *data)
 {
    int x;

    x = 0;
    data->player.ray_angle = data->player.routation_ang - rad(30);
    if( data->player.routation_ang <= 0.1 && data->player.routation_ang >= 0)
        data->player.ray_angle = rad(330);
    while(x < WIN_X)
    {
        // get_second_ver_cord(data);
        // hit_hor_wall(data); 
        check_intersictions(data);
        // get_intercepts(data);
        // draw_ray(data, data->cords.xb_hor , data->cords.yb_hor, GREEN);
        // draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
        data->player.ray_angle += rad(60)/ WIN_X;
        x ++;
    }
 }