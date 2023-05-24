/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:42:10 by aankote           #+#    #+#             */
/*   Updated: 2023/05/23 19:32:58 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_hit_ver(char **map, int x_cor, int y_cor)
{
    int x;
    int y;

    x = x_cor / CARE;
    y = y_cor / CARE;
    if(map[y][x] == '1' || map[y ][x- 1] == '1')
        return (0);
    return (1);
}

int get_intercepts_ver(t_data *data)
{
    double tang;
    
    tang =  tan(data->player.ray_angle);
    data->cords.xinterc_ver = floor(data->player.px_pos / CARE) * CARE;
    if(cos(data->player.ray_angle) >= 0)
        data->cords.xinterc_ver += CARE;
    data->cords.yinterc_ver = data->player.py_pos + tang * (data->cords.xinterc_ver - data->player.px_pos);
    if(data->cords.yinterc_ver >= data->win.map_y)
        data->cords.yinterc_ver = data->win.map_y - 1;
    if(data->cords.yinterc_ver <= 0)
        data->cords.yinterc_ver = 0;
    if(!check_hit_ver(data->map, data->cords.xinterc_ver, data->cords.yinterc_ver))
    {
        data->cords.xb_ver = data->cords.xinterc_ver;
        data->cords.yb_ver = data->cords.yinterc_ver ;
        // draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
        return (1); 
    }
    return (0);                                                                                                                 
}

int get_second_ver_cord(t_data *data)
{
    int look_down;
    int look_right;

    look_down = 0;
    look_right= 1;
    if(get_intercepts_ver(data))
    {
        // draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
        return(1);
    }
    if(sin(data->player.ray_angle) <= 0)// player looks down
        look_down = 1;
    if(cos(data->player.ray_angle) <= 0)// player looks left
        look_right = 0;
    data->cords.xb_ver = data->cords.xinterc_ver - CARE;
    data->cords.yb_ver = data->cords.yinterc_ver - tan(data->player.ray_angle) * CARE;
    if(look_right)
    {
        data->cords.xb_ver = data->cords.xinterc_ver + CARE;
        data->cords.yb_ver = data->cords.yinterc_ver + tan(data->player.ray_angle) * CARE;
    }
    if(data->cords.yb_ver >= data->win.map_y )
        data->cords.yb_ver = data->win.map_y - 1;
    if(data->cords.yb_ver <= 0)
        data->cords.yb_ver = 0;
    if(!check_hit_ver(data->map, data->cords.xb_ver, data->cords.yb_ver))
    {
       
        return (1);
    }
    return (0);
}

int   hit_ver_wall(t_data *data)
 {   
    int x_step;
    
    if(get_second_ver_cord(data))
    {
        draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
        return(1);
    }
    data->cords.ysteps_ver =  data->cords.yb_ver - data->cords.yinterc_ver;
    x_step = CARE;
    if(sin(data->player.ray_angle <= 0))//player looks down
        x_step = - CARE ;
    while(1)
    {
        if(data->cords.yb_ver >= data->win.map_y)
            data->cords.yb_ver = data->win.map_y - CARE;
        if(data->cords.yb_ver <= 0)
            data->cords.yb_ver = 0;
        if(!check_hit_ver(data->map, data->cords.xb_ver, data->cords.yb_ver))
        {
            draw_ray(data, data->cords.xb_ver , data->cords.yb_ver, GREEN);
            return (1);  
        }
        data->cords.xb_ver += x_step;
        data->cords.yb_ver += data->cords.ysteps_ver;
    }  
    return(0); 
 }