/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:12:50 by aankote           #+#    #+#             */
/*   Updated: 2023/06/15 15:43:37 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int create_window(t_win *win, t_data *data)
{
    win->mlx = mlx_init();
    win->mlx_win = mlx_new_window(win->mlx, WIN_X,
			WIN_Y, "SAIYANS cub3D");
    data->win = *win;
    return (0);
}

void draw_sky(t_img img)
{
    int x;
    int y;

    y = 0;
    while(y < WIN_Y / 2)
    {
        x = 0;
        while(x < WIN_X)
            my_mlx_pixel_put(&img, x ++, y, SKY);
        y ++;
    }
}

void draw_floor(t_img img)
{
  
    int x;
    int y;

    y = WIN_Y / 2;
    while(y < WIN_Y )
    {
        x = 0;
        while(x < WIN_X)
            my_mlx_pixel_put(&img, x ++, y, FLOOR);
        y ++;
    }
    
}

void draw_win(t_data *data)
{
    t_img img;
      
    img.img = mlx_new_image(data->win.mlx, WIN_X, WIN_Y);
    data->main_img = img;
    data->main_img.addr = mlx_get_data_addr(data->main_img.img, &data->main_img.bits_per_pixel, &data->main_img.line_length,
								&data->main_img.endian);
    draw_sky(data->main_img);   
    draw_floor(data->main_img);
    build_walls(data);
    mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->main_img.img, 0, 0);
}
