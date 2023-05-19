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

 void   draw_rays(t_data *data)
 {
    double yintercept;  
    double xintercept;        
    int check_down;
    int check_left;
    double bx;
    double by;
    // int check_right;

    check_down = 0;
    if(sin(data->player.routation_ang) <= 0)
        check_down = 1;
    yintercept = floor((data->player.py_pos) / CARE) * CARE;
    by = yintercept - CARE;
    if(!check_down)
    {
        yintercept += CARE ;
        by = yintercept + CARE;
    }
    check_left = 0; 
    if(cos(data->player.routation_ang) <= 0)
        check_left = 1;
    xintercept = data->player.px_pos + (yintercept  - data->player.py_pos) / tan(data->player.routation_ang);
    bx = fabs(CARE / tan(data->player.routation_ang)) +  xintercept;
    line_ray(data, bx , by, GREEN);    
 }