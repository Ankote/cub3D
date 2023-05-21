/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:42:10 by aankote           #+#    #+#             */
/*   Updated: 2023/05/21 11:02:23 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_intercepts_ver(t_data *data)
{


    int look_right;
    
    data->cords.xinterc_ver = floor(data->player.px_pos / CARE) * CARE;
    if(cos(data->player.ray_angle >= 0))
        look_right = 1;
    else
         look_right = 0;
    printf("%d\n", look_right);
    if(look_right == 1)
    {
        data->cords.xinterc_ver += CARE;
        data->cords.yinterc_ver = data->player.py_pos + tan(data->player.ray_angle) * (data->cords.xinterc_ver - data->player.px_pos);
    }
    else
    {
        data->cords.yinterc_ver = data->player.py_pos + tan(data->player.ray_angle) * (data->cords.xinterc_ver - data->player.px_pos );
    }
    // draw_ray(data, data->cords.xinterc_ver,  data->cords.yinterc_ver, GREEN);                                                                                                                          
}


void get_second_ver_cord(t_data *data)
{
    int look_down;
    int look_right;
    int x;
    int y;

    get_intercepts_ver(data);
    look_down = 0;
    if(sin(data->player.ray_angle) <= 0)
        look_down = 1;
    look_right= 1;
    if(cos(data->player.ray_angle) <= 0)
        look_right = 0;
    data->cords.xb_ver = data->cords.xinterc_ver - CARE;
    data->cords.yb_ver = data->cords.yinterc_ver - tan(data->player.ray_angle) * CARE;
    if(look_right)
    {
        data->cords.xb_ver = data->cords.xinterc_ver + CARE;
        data->cords.yb_ver = data->cords.yinterc_ver + tan(data->player.ray_angle) * CARE;
    }
    x = data->cords.xinterc_ver / CARE;
    y = data->cords.yinterc_ver / CARE;
    if(data->map[y][x - 1] == '1')
    {
        data->cords.xb_ver = data->cords.xinterc_ver;
        data->cords.yb_ver = data->cords.yinterc_ver;
    }
}


void   hit_ver_wall(t_data *data)
 {   
    int x;
    int y;

    get_second_ver_cord(data);
    data->cords.ysteps_ver =  data->cords.yb_ver - data->cords.yinterc_ver;
    while(1)
    {
        x = data->cords.xb_ver / CARE;
        y = data->cords.yb_ver / CARE;
        if(data->map[y][x - 1] == '1')
        {
            draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
            return;
        }
        data->cords.xb_ver += CARE;
        data->cords.yb_ver += data->cords.ysteps_ver;
        x = data->cords.xb_ver / CARE;
        y = data->cords.yb_ver / CARE;
        if(data->map[y][x - 1] == '1')
        {
            draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
            return;
        }
    }   
 }