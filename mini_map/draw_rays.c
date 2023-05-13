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
 


 void line_ray(t_data *data, double x0, double y0, double dx, double dy)
 {
    double steps;
    double i;
    double xinc;
    double yinc;

    i = 0;
    steps = fabs(dx);
    if(fabs(dy) > fabs(dx))
        steps = fabs(dy);
    xinc = dx / steps;
    yinc = dy / steps;
    while(i < steps)
    {
        my_mlx_pixel_put(&data->img, x0, y0, RED);
        x0 += xinc;
        y0 += yinc;
        i ++;
    }
 }
 
 void draw_rays(t_data *data)
 {
    double dx;
    double dy;
    
    dx = cos(data->player.routation_ang) * 20;
    dy = sin(data->player.routation_ang) * 20;
    
    line_ray(data, data->player.px_pos + 3, data->player.py_pos + 3, dx, dy );
 }