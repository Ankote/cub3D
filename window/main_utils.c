/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:37:57 by aankote           #+#    #+#             */
/*   Updated: 2023/06/12 18:31:35 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_wall_l(t_data *data, double x0, double y0, int x1, int y1, int color)
{
    int steps;
    int xinc;
    int yinc;
    int i;

    i = 0;
    steps = fabs(x1- (x0));
    if(fabs(y1 - y0) > fabs(x1- x0))
        steps = fabs(y1 - y0);
    xinc = (x1- x0) / steps;
    yinc = (y1 - y0) / steps;
    x1=  x0;
    y1 = y0;
    while(i < steps)
    {
        my_mlx_pixel_put(&data->main_img, x1, y1, color);
        x1 += xinc;
        y1 += yinc;
        i ++;
    }
}

void draw_wall(t_data *data, double ray_dst, int x)
{
    double dst_proj_plan;
    double wall_height;
    double y_start;
    double y_end;
    
    dst_proj_plan = (WIN_X / 2) / tan(rad(FOV) / 2);
    wall_height = ((CARE / ray_dst) * dst_proj_plan);
    y_start = (WIN_Y / 2) - (wall_height / 2);
    if(y_start < 0)
        y_start = 0;
    y_end = y_start + wall_height;
    if(y_end > WIN_Y)
        y_end = WIN_Y;
    draw_wall_l(data,x , y_start, x, y_end, RED);
}


void build_walls(t_data *data)
{
    int x;
    double ds;

    x = 0;
    data->player.ray_angle = data->player.routation_ang - rad(30);
    if( data->player.routation_ang <= 0.1 && data->player.routation_ang >= 0)
        data->player.ray_angle = rad(330);
    while(x < WIN_X)
    {
        ds = check_intersictions(data);
        data->player.ray_angle += rad(60) / WIN_X;
        ds = ds * cos(data->player.ray_angle - data->player.routation_ang);
        draw_wall(data, ds, x);
        x ++;
    }
 }