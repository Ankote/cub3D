/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:12:05 by aankote           #+#    #+#             */
/*   Updated: 2023/06/17 21:28:12 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int draw_squart(t_data *data ,int x, int y)
{
    int x0;
    int y0;

    y0 = y;
    while(y < y0 )
    {
        x0 = x;
        while(x0 < x + CARE)
        {
            if(data->map->map_copy[y / CARE][x / CARE] == '1')
                my_mlx_pixel_put(&data->main_img, x0 ++, y, WALL);
            else if(data->map->map_copy[y / CARE][x / CARE] == '0' || is_player(data->map->map_copy[y / CARE][x / CARE]))
                my_mlx_pixel_put(&data->main_img, x0 ++, y, WAY);
            else
                x0 ++;
        }
        y ++;
    }
    return (0);
}

int draw_lines(t_data *data)
{
    int x;
    int y;

    y = 0;
    while(y < data->win.map_y )
    {
        x = 0;
        while (x < data->win.map_x)
        {
            if(x % CARE == 0 || y % CARE == 0)
                my_mlx_pixel_put(&data->main_img, x, y, LINE);
            x ++;
        }
        y ++;
    }
    return (0);
}

int draw_player(t_data *data)
{
    int x;
    int y;

    y = MAP_Y / 2;
    while(y < MAP_Y / 2 + P_SIZE)
    {
        x = MAP_X / 2;
        while(x < MAP_X / 2+ P_SIZE)
             my_mlx_pixel_put(&data->main_img, x++, y, PLAYER);
        y ++;
    }
    return (0);
}

// int draw_map(t_data *data)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
// 	// get_dimensions(data);
//     while(y < data->win.map_y)
//     {
//         x = 0;
//         while(x < data->win.map_x)
//         {
//             draw_squart(data, x , y);
//             x += CARE;
//         }
//         y += CARE;
//     }
//     return (0);
// }

// int draw_map(t_data *data)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
// 	get_dimensions(data);
//     while(y < data->win.map_y)
//     {
//         x = 0;
//         while(x < data->win.map_x)
//         {
//             draw_squart(data, x , y);
//             x += CARE;
//         }
//         y += CARE;
//     }
//     return (0);
// }

void draw_map(t_data *data)
{
    int x;
    int y;
    int mx;
    int my;
    
    my =  (data->player.py_pos / 4 - MAP_Y / 2) - 16;
    y = -1;
    while(++y < MAP_Y)
    {
        x = -1;
        mx = (data->player.px_pos / 4 - MAP_X / 2) - 16;
        while(++x < MAP_X)
        {
            if(mx  / 16  > 0 && my  / 16 > 0 && mx   < data->win.map_x   && my < data->win.map_y )
            {
                if(data->map->map_copy[my / 16][mx / 16] == '1')
                {
                    my_mlx_pixel_put(&data->main_img, x, y, WALL);
                }
                else if(data->map->map_copy[my / 16][mx / 16] == '0')
                    my_mlx_pixel_put(&data->main_img, x, y, YELLOW);
                }
            // printf("%d %d\n", mx ,my);
            mx ++;
        }
        my ++;
    }
}