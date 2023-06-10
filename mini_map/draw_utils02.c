/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:47:28 by aankote           #+#    #+#             */
/*   Updated: 2023/06/10 09:56:57 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void draw_ray(t_data *data, double x, double y, int color)
// {
//     double steps;
//     double xinc;
//     double yinc;
//     int i;

//     i = 0;
//     steps = fabs(x - (data->player.px_pos - P_SIZE / 2));
//     if(fabs(y - data->player.py_pos - P_SIZE / 2) > fabs(x - data->player.px_pos - P_SIZE / 2))
//         steps = fabs(y - data->player.py_pos - P_SIZE / 2);
//     xinc = (x - data->player.px_pos - P_SIZE / 2) / steps;
//     yinc = (y - data->player.py_pos - P_SIZE / 2) / steps;
//     x =  data->player.px_pos + P_SIZE / 2;
//     y = data->player.py_pos + P_SIZE / 2;
//     while(i < steps)
//     {
//         my_mlx_pixel_put(&data->img, x, y, color);
//         x += xinc;
//         y += yinc;
//         i ++;
//     }
// }

void draw_ray(t_data *data, double x, double y, int color)
{
    int steps;
    double xinc;
    double yinc;
    int i;

    i = 0;
    steps = fabs(x - (data->player.px_pos - P_SIZE / 2));
    if(fabs(y - data->player.py_pos - P_SIZE / 2) > fabs(x - data->player.px_pos - P_SIZE / 2))
        steps = fabs(y - data->player.py_pos - P_SIZE / 2);
    xinc = (x - data->player.px_pos - P_SIZE / 2) / steps;
    yinc = (y - data->player.py_pos - P_SIZE / 2) / steps;
    x =  data->player.px_pos + P_SIZE / 2;
    y = data->player.py_pos + P_SIZE / 2;
    while(i < steps)
    {
        my_mlx_pixel_put(&data->img, (int)x, (int)y, color);
        x += xinc;
        y += yinc;
        i ++;
    }
}
 
 void draw_p_dir(t_data *data)
{
    double x;
    double y;

    x = cos(data->player.routation_ang) * 21 + data->player.px_pos + P_SIZE / 2;
    y = sin(data->player.routation_ang) * 21 + data->player.py_pos + P_SIZE / 2;
    draw_ray(data, x, y, RED);
}
