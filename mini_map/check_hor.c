/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:31:04 by aankote           #+#    #+#             */
/*   Updated: 2023/05/20 13:58:54 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../cub3d.h"
 
void get_intercepts(t_data *data)
{

    int check_down;
    
    check_down = 0;
    if(sin(data->player.ray_angle) <= 0)
        check_down = 1;
    data->cords.yinterc_hor = floor((data->player.py_pos) / CARE) * CARE;
    if(!check_down)
        data->cords.yinterc_hor += CARE ;
    data->cords.xinterc_hor = data->player.px_pos + (data->cords.yinterc_hor  - data->player.py_pos) / tan(data->player.ray_angle);
}



void get_second_hor_cord(t_data *data)
{
    int check_down;
    int check_left;
    int x;
    int y;

    get_intercepts(data);
    check_down = 0;
    if(sin(data->player.ray_angle) <= 0)
        check_down = 1;
    data->cords.yb = data->cords.yinterc_hor - CARE;
    if(!check_down)
        data->cords.yb = data->cords.yinterc_hor + CARE;
    check_left = 0; 
    if(cos(data->player.ray_angle) <= 0)
        check_left = 1;
    data->cords.xinterc_hor = data->player.px_pos + (data->cords.yinterc_hor  - data->player.py_pos) / tan(data->player.ray_angle);
    if(!check_left)
        data->cords.xb = fabs(CARE / tan(data->player.ray_angle)) +  data->cords.xinterc_hor;
    else
        data->cords.xb = -fabs(CARE / tan(data->player.ray_angle)) +  data->cords.xinterc_hor;
    
    x = data->cords.xinterc_hor / CARE;
    y = data->cords.yinterc_hor / CARE;
    if(data->map[y - 1][x] == '1')
    {
        data->cords.xb = data->cords.xinterc_hor;
        data->cords.yb = data->cords.yinterc_hor;
    }
}

void   hit_hor_wall(t_data *data)
 {   
    int x;
    int y;

    get_second_hor_cord(data);
    data->cords.xsteps =  data->cords.xb - data->cords.xinterc_hor;
    while(1)
    {
        x = data->cords.xb / CARE;
        y = data->cords.yb / CARE;
        if(data->map[y - 1][x] == '1')
        {
            draw_ray(data, data->cords.xb , data->cords.yb, GREEN);
            return;
        }
        data->cords.xb += data->cords.xsteps;
        data->cords.yb -= CARE;
        x = data->cords.xb / CARE;
        y = data->cords.yb / CARE;
        if(data->map[y - 1][x] == '1')
        {
            draw_ray(data, data->cords.xb , data->cords.yb, GREEN);
            return;
        }
    }   
 }

 void draw_rays(t_data *data)
 {
    // data->player.ray_angle = data->player.routation_ang - rad(30);
    // while(data->player.ray_angle <= data->player.routation_ang + rad(30))
    // {
    //     hit_hor_wall(data);
    //     data->player.ray_angle += rad(60)/ data->win.map_y;
    // }
     get_intercepts_ver(data);
 }