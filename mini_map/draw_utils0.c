/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:21:39 by aankote           #+#    #+#             */
/*   Updated: 2023/06/17 10:55:08 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_player(int c)
{
    if(c == 'E' || c == 'W')
        return (1);
    if(c == 'S' || c == 'N')
        return (1);
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
    
    y = data->player.py_pos;
    while(y < data->player.py_pos + P_SIZE)
    {
        x = data->player.px_pos;
        while(x < data->player.px_pos + P_SIZE)
             my_mlx_pixel_put(&data->main_img, x++, y, RED);
        y ++;
    }
    return (0);
}

int draw_squart(t_data *data ,int x, int y)
{
    int x0;
    int y0;
    
    y0 = y;
    while(y < y0 + CARE)
    {
        x0 = x;
        while(x0 < x + CARE)
        {
            if(data->map[y / CARE][x / CARE] == '1')
                my_mlx_pixel_put(&data->main_img, x0 ++, y, WALL);
            else if(data->map[y / CARE][x / CARE] == '0' || is_player(data->map[y / CARE][x / CARE]))
                my_mlx_pixel_put(&data->main_img, x0 ++, y, WAY);
            else
                x0 ++;
        }
        y ++;
    }
    return (0);
}

int draw_map(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
	get_dimensions(data);
    while(y < data->win.map_y)
    {
        x = 0;   
        while(x < data->win.map_x)
        {
            draw_squart(data, x , y);
            x += CARE;
        }
        y += CARE;
    }
    return (0);
}

// int draw_map(t_data *data)
// {
//     int x;
//     int y;
//     int xin;
//     int yin;
    
//     y = data->player.py_pos - 150;
 
//     // if(y < 0)
//     //     y = CARE;
//     yin = 0;
//     while(yin < 300 && y < data->win.map_y && y > 0)
//     {
//         xin = 0;
//         x = data->player.px_pos - 150;
//         // if(x < 0)
//         //     x = CARE;
//         while(xin < 300 && x < data->win.map_x && x > 0)
//         {
//             if(data->map[y / CARE ][x / CARE ] == '1')
//                 my_mlx_pixel_put(&data->main_img, xin, yin, WALL);
//             xin ++;
//             x ++;
//         }
//         y ++;
//         yin++;
//     }
//     return (0);
// }

// int	draw_map(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	c;

// 	i = -1;
// 	while (data->map[++i])
// 	{
// 		j = -1;
// 		while (data->map[i][++j])
// 		{
// 			c = (j * CARE) - 1;
// 			if (data->map[i][j] == '1'
// 				|| (i > 0 && data->map[i - 1][j] == '1'))
// 				while (++c < (j + 1) * CARE)
// 					my_mlx_pixel_put1(data, &data->main_img, j * CARE, c, 16776960);
// 			c = (i * CARE) - 1;
// 			if (data->map[i][j] == '1'
// 				|| (j > 0 && data->map[i][j - 1] == '1'))
// 				while (++c < (i + 1) * CARE)
// 					my_mlx_pixel_put1(data, &data->main_img, j * CARE, c, 16776960);
// 		}
// 	}
//     return(0);
// }
