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
    steps = fabs(x - data->player.px_pos + 3);
    if(fabs(x - data->player.py_pos + 3) > fabs(x - data->player.px_pos + 3))
        steps = fabs(x - data->player.py_pos + 3);
    xinc = (x - data->player.px_pos + 3) / steps;
    yinc = (y - data->player.py_pos + 3) / steps;
    x =  data->player.px_pos + 3;
    y = data->player.py_pos + 3;
    while(i < steps)
    {
        my_mlx_pixel_put(&data->img, x, y, RED);
        x += xinc;
        y += yinc;
        i ++;
    }
 }
 
 void draw_rays(t_data *data)
 {
    double x;
    double y;
    
    x = cos(data->player.routation_ang) * 20 + data->player.px_pos;
    y = sin(data->player.routation_ang) * 20 + data->player.py_pos;
    
    line_ray(data, x, y, GREEN);
 }