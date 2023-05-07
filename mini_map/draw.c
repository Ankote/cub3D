/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:21:39 by aankote           #+#    #+#             */
/*   Updated: 2023/05/06 15:30:44 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int draw_squart(t_mlxk window ,int x, int y)
{
    int x0;
    int y0;
    
    y0 = y;
    while(y < y0 + CARE)
    {
        x0 = x;
        while(x0 < x + CARE)
             mlx_pixel_put(window.mlx, window.mlx_win,  x0++, y, WAY);
        y ++;
    }
    return (0);
}

int draw_lines(t_mlxk win)
{
    int x;
    int y;

    y = 0;
    while(y < MAP_Y)
    {
        x = 0;
        while (x < MAP_X)
        {
            if(x % CARE == 0 || y % CARE == 0)
            {
                mlx_pixel_put(win.mlx, win.mlx_win,  x, y, LINE);
                
            }
            x ++;
        }
        y ++;
    }
    return (0);
}

int draw_player(t_data *data, int x_pos, int y_pos)
{
    int x;
    int y;

    y = y_pos;
    while(y < y_pos + 7)
    {
        x = x_pos;
        while(x < x_pos + 7)
             mlx_pixel_put(data->win.mlx, data->win.mlx_win,  x++, y, PLAYER);
        y ++;
    }
    return (0);
}

int replace_player(t_data *data, int x_pos, int y_pos)
{
     int x;
    int y;

    y = y_pos;
    while(y < y_pos + 7)
    {
        x = x_pos;
        while(x < x_pos + 7)
             mlx_pixel_put(data->win.mlx, data->win.mlx_win,  x++, y, WAY);
        y ++;
    }
    return (0);
}
int draw_map(t_mlxk  window)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < MAP_Y)
    {
        x = 0;
        while(x < MAP_X)
        {
            draw_squart(window, x , y);
            x += CARE;
        }
        y += CARE;
    }
    return (0);
}