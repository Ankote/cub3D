/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:31:04 by aankote           #+#    #+#             */
/*   Updated: 2023/05/11 13:57:46 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../cub3d.h"
 


 void line_ray(t_data *data, double x, double y, int color)
 {
    double steps;
    double xinc;
    double yinc;
    int i;

    i = 0;
    steps = fabs(x - (data->player.px_pos - 3));
    if(fabs(x - data->player.py_pos - 3) > fabs(x - data->player.px_pos - 3))
        steps = fabs(x - data->player.py_pos - 3);
    xinc = (x - data->player.px_pos - 3) / steps;
    yinc = (y - data->player.py_pos - 3) / steps;
    x =  data->player.px_pos + 3;
    y = data->player.py_pos + 3;
    while(i < steps)
    {
        my_mlx_pixel_put(&data->img, x, y, color);
        x += xinc;
        y += yinc;
        i ++;
    }
 }
 
 void draw_p_dir(t_data *data)
 {
    double x;
    double y;

    x = cos(data->player.routation_ang) * 20 + data->player.px_pos + 3;
    y = sin(data->player.routation_ang) * 20 + data->player.py_pos + 3;
    line_ray(data, x, y, RED);
 }

void get_intercepts(t_data *data)
{

    int check_down;
    int check_left;
    
    check_down = 0;
    if(sin(data->player.ray_angle) <= 0)
        check_down = 1;
    data->cords.yintercept = floor((data->player.py_pos) / CARE) * CARE;
    if(!check_down)
        data->cords.yintercept += CARE ;
    check_left = 0; 
    if(cos(data->player.ray_angle) <= 0)
        check_left = 1;
    data->cords.xintercept = data->player.px_pos + (data->cords.yintercept  - data->player.py_pos) / tan(data->player.ray_angle);
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
    data->cords.yb = data->cords.yintercept - CARE;
    if(!check_down)
        data->cords.yb = data->cords.yintercept + CARE;
    check_left = 0; 
    if(cos(data->player.ray_angle) <= 0)
        check_left = 1;
    data->cords.xintercept = data->player.px_pos + (data->cords.yintercept  - data->player.py_pos) / tan(data->player.ray_angle);
    if(!check_left)
        data->cords.xb = fabs(CARE / tan(data->player.ray_angle)) +  data->cords.xintercept;
    else
        data->cords.xb = -fabs(CARE / tan(data->player.ray_angle)) +  data->cords.xintercept;
    
    x = data->cords.xintercept / CARE;
    y = data->cords.yintercept / CARE;
    if(data->map[y - 1][x] == '1')
    {
        data->cords.xb = data->cords.xintercept;
        data->cords.yb = data->cords.yintercept;
    }
}

// void   draw_ray(t_data *data)
//  {   
//     int check_down;
//     int check_left;
//     double bx;
//     double by;
//     double xsteps;

//     int x;
//     int y;
//     check_down = 0;
//     if(sin(data->player.ray_angle) <= 0)
//         check_down = 1;
//     data->cords.yintercept = floor((data->player.py_pos) / CARE) * CARE;
//     by = data->cords.yintercept - CARE;
//     if(!check_down)
//     {
//         data->cords.yintercept += CARE ;
//         by = data->cords.yintercept + CARE;
//     }
//     check_left = 0; 
//     if(cos(data->player.ray_angle) <= 0)
//         check_left = 1;
//     data->cords.xintercept = data->player.px_pos + (data->cords.yintercept  - data->player.py_pos) / tan(data->player.ray_angle);
//     if(!check_left)
//         bx = fabs(CARE / tan(data->player.ray_angle)) +  data->cords.xintercept;
//     else
//         bx = -fabs(CARE / tan(data->player.ray_angle)) +  data->cords.xintercept;
//     xsteps = bx - data->cords.xintercept;
//     while(1)
//     {
//         x = data->cords.xintercept / CARE;
//         y = data->cords.yintercept / CARE;
//         if(data->map[y - 1][x] == '1')
//         {
//             line_ray(data, data->cords.xintercept , data->cords.yintercept, GREEN);
//             return;
//         }
           
//         /*******************/
//         x = bx / CARE;
//         y = by / CARE;
//         if(data->map[y - 1][x] == '1')
//         {
//             line_ray(data, bx , by, GREEN);
//             return;
//         }
//         /******************************/
//         bx += xsteps;
//         by -= CARE;
//         x = bx / CARE;
//         y = by / CARE;
//         if(data->map[y - 1][x] == '1')
//         {
//             line_ray(data, bx , by, GREEN);
//             return;
//         }
//     }
//     line_ray(data, bx , by, GREEN);    
//  }


void   draw_ray(t_data *data)
 {   
    int x;
    int y;

    get_second_hor_cord(data);
    data->cords.xsteps =  data->cords.xb - data->cords.xintercept;
    while(1)
    {
        // x = data->cords.xintercept / CARE;
        // y = data->cords.yintercept / CARE;
        // if(data->map[y - 1][x] == '1')
        // {
        //     line_ray(data, data->cords.xintercept , data->cords.yintercept, GREEN);
        //     return;
        // }
        x = data->cords.xb / CARE;
        y = data->cords.yb / CARE;
        if(data->map[y - 1][x] == '1')
        {
            line_ray(data, data->cords.xb , data->cords.yb, GREEN);
            return;
        }
        data->cords.xb += data->cords.xsteps;
        data->cords.yb -= CARE;
        x = data->cords.xb / CARE;
        y = data->cords.yb / CARE;
        if(data->map[y - 1][x] == '1')
        {
            line_ray(data, data->cords.xb , data->cords.yb, GREEN);
            return;
        }
    }   
 }

 void draw_rays(t_data *data)
 {
    data->player.ray_angle = data->player.routation_ang - rad(30);
    while(data->player.ray_angle <= data->player.routation_ang + rad(30))
    {
        draw_ray(data);
        data->player.ray_angle += rad(60)/ data->win.map_y;
    }
 }